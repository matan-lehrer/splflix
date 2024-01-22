#pragma once

#include <exception>


class BreakLoopException : public std::exception
{
    public:
        const char* what() const noexcept override;
};
