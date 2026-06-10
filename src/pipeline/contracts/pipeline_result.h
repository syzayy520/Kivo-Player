// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/pipeline/contracts/pipeline_result.h - Pipeline result type.
// Depends on: pipeline_error.h, standard library.

#pragma once
#include "pipeline_error.h"
#include <variant>

namespace kivo::pipeline {

template<typename T>
struct PipelineResult {
    std::variant<T, PipelineError> value{};

    constexpr auto is_ok() const noexcept -> bool {
        return std::holds_alternative<T>(value);
    }
    constexpr auto is_err() const noexcept -> bool {
        return std::holds_alternative<PipelineError>(value);
    }
    auto unwrap() const -> T const& {
        return std::get<T>(value);
    }
    auto error() const -> PipelineError const& {
        return std::get<PipelineError>(value);
    }

    static auto ok(T const& v) -> PipelineResult<T> {
        return PipelineResult<T>{v};
    }
    static auto err(PipelineError const& e) -> PipelineResult<T> {
        return PipelineResult<T>{e};
    }
};

} // namespace kivo::pipeline
