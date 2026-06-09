// tests/unit/core/playback_command_tests.cpp
#include "core/command/playback_command.h"
#include <cstdio>

namespace kivo::playback {
static int cc=0, fc=0;
static void chk(bool c, const char* m){ ++cc; if(!c){++fc; printf("[FAIL] %s\n",m);} }
static int rpt(){ printf("[%s] command_tests: %d checks\n", fc==0?"PASS":"FAIL", cc); return fc?1:0; }
}

int main(){
    using namespace kivo::playback;
    cc=fc=0;
    // OpenMedia non-empty passes validation
    {   auto r = validate_command(CmdOpenMedia{"file.mp4"});
        chk(r.is_success(), "OpenMedia non-empty valid");
    }
    // OpenMedia empty fails
    {   auto r = validate_command(CmdOpenMedia{""});
        chk(r.is_failure(), "OpenMedia empty invalid");
    }
    // SetPlaybackRate 1.0 valid
    {   auto r = validate_command(CmdSetPlaybackRate{1.0});
        chk(r.is_success(), "rate 1.0 valid");
    }
    // SetPlaybackRate 0.1 invalid (below 0.25)
    {   auto r = validate_command(CmdSetPlaybackRate{0.1});
        chk(r.is_failure(), "rate 0.1 invalid");
    }
    // SetVolume 0.5 valid
    {   auto r = validate_command(CmdSetVolume{0.5});
        chk(r.is_success(), "volume 0.5 valid");
    }
    // SetVolume -0.1 invalid
    {   auto r = validate_command(CmdSetVolume{-0.1});
        chk(r.is_failure(), "volume -0.1 invalid");
    }
    return rpt();
}
