module;

#include <guiddef.h>

#include <combaseapi.h>

#include <string>

#include <vector>

#include <stdexcept>

export module CHV4DTBASIC:CHV4DHVID;

export namespace CHV4DTBASIC
{
	class CHV4DHVID
	{
	public:
		CHV4DHVID();

		CHV4DHVID(std::wstring const& uuid);

		CHV4DHVID(GUID const& uuid);

		CHV4DHVID(CHV4DHVID const& uuid);

	public:
		void operator = (std::wstring const& uuid);

		void operator = (GUID const& uuid);

		void operator = (CHV4DHVID const& uuid);

		bool operator == (std::wstring const& uuid) const;

		bool operator == (GUID const& uuid) const;

		bool operator == (CHV4DHVID const& uuid) const;

		bool operator != (std::wstring const& uuid) const;

		bool operator != (GUID const& uuid) const;

		bool operator != (CHV4DHVID const& uuid) const;

		bool operator < (std::wstring const& uuid) const;

		bool operator < (GUID const& uuid) const;

		bool operator < (CHV4DHVID const& uuid) const;

		bool operator > (std::wstring const& uuid) const;

		bool operator > (GUID const& uuid) const;

		bool operator > (CHV4DHVID const& uuid) const;

		GUID operator()() const;

	public:
		void Generate();

		void ToString(GUID const& uuid, std::wstring& str) const;

		void ToHVID(std::wstring const& str, GUID& uuid) const;

	private:
		GUID tagUUID{};

	};

}

