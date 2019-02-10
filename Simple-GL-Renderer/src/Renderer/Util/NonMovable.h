#pragma once

class NonMovable
{
public:

	NonMovable(const NonMovable&&) = delete;
	NonMovable& operator=(const NonMovable&&) = delete;

protected:

	NonMovable() = default;
	virtual ~NonMovable() = default;

};