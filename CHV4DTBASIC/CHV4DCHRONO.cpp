module;

#include <guiddef.h>

#include <string>

#include <stdexcept>

#include <chrono>

module CHV4DTBASIC:CHV4DCHRONO;

namespace CHV4DTBASIC
{
	CHV4DCHRONO::CHV4DCHRONO()
	{


		return;

	}

	CHV4DCHRONO::CHV4DCHRONO(std::chrono::system_clock::time_point const& chrono)
	{
		tagCHRONO = chrono;

		return;

	}

	CHV4DCHRONO::CHV4DCHRONO(CHV4DCHRONO const& chrono)
	{
		tagCHRONO = chrono.tagCHRONO;

		return;

	}

	void CHV4DCHRONO::operator = (uint64_t const& chrono)
	{
		tagCHRONO = std::chrono::system_clock::from_time_t(chrono);

		return;

	}

	void CHV4DCHRONO::operator = (std::chrono::system_clock::time_point const& chrono)
	{
		tagCHRONO = chrono;

		return;

	}

	void CHV4DCHRONO::operator = (CHV4DCHRONO const& chrono)
	{
		tagCHRONO = chrono.tagCHRONO;

		return;

	}

	bool CHV4DCHRONO::operator == (uint64_t const& chrono) const
	{
		auto temp = std::chrono::system_clock::from_time_t(chrono);

		return tagCHRONO == temp;

	}

	bool CHV4DCHRONO::operator == (std::chrono::system_clock::time_point const& chrono) const
	{
		return tagCHRONO == chrono;

	}

	bool CHV4DCHRONO::operator == (CHV4DCHRONO const& chrono) const
	{
		return tagCHRONO == chrono.tagCHRONO;

	}

	bool CHV4DCHRONO::operator != (uint64_t const& chrono) const
	{
		auto temp = std::chrono::system_clock::from_time_t(chrono);

		return !(tagCHRONO == temp);

	}

	bool CHV4DCHRONO::operator != (std::chrono::system_clock::time_point const& chrono) const
	{
		return !(tagCHRONO == chrono);

	}

	bool CHV4DCHRONO::operator != (CHV4DCHRONO const& chrono) const
	{
		return !(tagCHRONO == chrono.tagCHRONO);

	}

	bool CHV4DCHRONO::operator < (uint64_t const& chrono) const
	{
		auto temp = std::chrono::system_clock::from_time_t(chrono);

		return tagCHRONO < temp;

	}

	bool CHV4DCHRONO::operator < (std::chrono::system_clock::time_point const& chrono) const
	{
		return tagCHRONO < chrono;

	}

	bool CHV4DCHRONO::operator < (CHV4DCHRONO const& chrono) const
	{
		return tagCHRONO < chrono.tagCHRONO;

	}

	bool CHV4DCHRONO::operator > (uint64_t const& chrono) const
	{
		auto temp = std::chrono::system_clock::from_time_t(chrono);

		return tagCHRONO > temp;

	}

	bool CHV4DCHRONO::operator > (std::chrono::system_clock::time_point const& chrono) const
	{
		return tagCHRONO > chrono;

	}

	bool CHV4DCHRONO::operator > (CHV4DCHRONO const& chrono) const
	{
		return tagCHRONO > chrono.tagCHRONO;

	}

	std::chrono::system_clock::time_point CHV4DCHRONO::operator()() const
	{
		return tagCHRONO;

	}

	void CHV4DCHRONO::Current()
	{
		tagCHRONO = std::chrono::system_clock::now();

		return;

	}

}