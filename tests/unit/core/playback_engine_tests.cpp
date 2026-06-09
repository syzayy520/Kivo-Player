// tests/unit/core/playback_engine_tests.cpp
#include "core/engine/playback_engine.h"
#include "core/event/playback_event_sink.h"
#include <cstdio>
#include <vector>

namespace kivo::playback {
struct MockSink : IPlaybackEventSink {
    std::vector<PlaybackEvent> events;
    void on_event(PlaybackEvent const& e) override { events.push_back(e); }
};
}

static int cc=0, fc=0;
static void chk(bool c, const char* m){ ++cc; if(!c){++fc; printf("[FAIL] %s\n",m);} }
static int rpt(){ printf("[%s] engine_tests: %d checks\n", fc==0?"PASS":"FAIL", cc); return fc?1:0; }

int main(){
    using namespace kivo::playback;
    cc=fc=0;

    // Idle + valid OpenMedia -> Success, states: Idle->Opening->Ready
    {
        MockSink sink; PlaybackEngine eng(&sink);
        auto r = eng.execute(CmdOpenMedia{"test.mp4"});
        chk(r.is_success(), "OpenMedia success");
        chk(eng.current_state() == PlaybackState::Ready, "state Ready after open");
        // Should NOT emit MediaOpened/MediaReady (P0-001 rule)
        bool hasOpened = false;
        for(auto& e: sink.events) if(std::holds_alternative<EvMediaOpened>(e)) hasOpened=true;
        chk(!hasOpened, "no MediaOpened emitted");
    }

    // Idle + invalid OpenMedia -> Failure, no state change
    {
        MockSink sink; PlaybackEngine eng(&sink);
        auto r = eng.execute(CmdOpenMedia{""});
        chk(r.is_failure(), "OpenMedia empty fails");
        chk(eng.current_state() == PlaybackState::Idle, "state still Idle");
    }

    // Ready + Play -> Success, state Ready->Playing
    {
        MockSink sink; PlaybackEngine eng(&sink);
        eng.execute(CmdOpenMedia{"x"});
        auto r = eng.execute(CmdPlay{});
        chk(r.is_success(), "Play success");
        chk(eng.current_state() == PlaybackState::Playing, "state Playing");
    }

    // Playing + Pause -> Success, state Playing->Paused
    {
        MockSink sink; PlaybackEngine eng(&sink);
        eng.execute(CmdOpenMedia{"x"}); eng.execute(CmdPlay{});
        auto r = eng.execute(CmdPause{});
        chk(r.is_success(), "Pause success");
        chk(eng.current_state() == PlaybackState::Paused, "state Paused");
    }

    // Closed + Close -> Success, no event
    {
        MockSink sink; PlaybackEngine eng(&sink);
        eng.execute(CmdOpenMedia{"x"}); eng.execute(CmdPlay{});
        eng.execute(CmdStop{}); eng.execute(CmdClose{});
        sink.events.clear();
        auto r = eng.execute(CmdClose{});
        chk(r.is_success(), "Close on Closed idempotent");
        chk(sink.events.empty(), "no events on idempotent Close");
    }

    return rpt();
}
