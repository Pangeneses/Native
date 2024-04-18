module;

#include <combaseapi.h>

#include <string>

#include <stdexcept>

export module CHV4DTBASIC:CHV4DHASH;

import :CHV4DHVID;
import :CHV4DTEXTBLOBW;

export namespace CHV4DTBASIC
{
	class CHV4DHASH
	{
	public:
		CHV4DHASH(std::wstring const& hash);

		CHV4DHASH(std::wstring const& uuid, std::wstring const& hash);

		CHV4DHASH(GUID const& uuid, std::wstring const& hash);

		CHV4DHASH(CHV4DHASH const& hash);

	public:
		bool operator == (std::pair<GUID, std::wstring> const& hash) const;

		bool operator == (CHV4DHASH const& hash) const;

		bool operator != (std::pair<GUID, std::wstring> const& hash) const;

		bool operator != (CHV4DHASH const& hash) const;

		bool operator < (std::pair<GUID, std::wstring> const& hash) const;

		bool operator < (CHV4DHASH const& hash) const;

		bool operator > (std::pair<GUID, std::wstring> const& hash) const;

		bool operator > (CHV4DHASH const& hash) const;

		std::pair<GUID, std::wstring> operator()() const;

	private:
		CHV4DHVID tagHVID{};

		CHV4DTEXTBLOBW tagMAXPATH{};

	};

	struct CHV4DHASHFN
	{
		bool operator()(CHV4DHASH const& lh, CHV4DHASH const& rh) const
		{
			return memcmp(&lh, &rh, sizeof(CHV4DHASH)) < 0;

		}

		std::size_t operator() (CHV4DHASH const& k) const
		{
			GUID uuid = k().first;

			long long a{ 0 }, b{ 0 };
							
			std::memcpy(&a, &uuid.Data1, sizeof(long long));

			std::memcpy(&b, &uuid.Data4, sizeof(long long));

			std::size_t h1{}, h2{};

			h1 = std::hash<long long>{}(a);

			h2 = std::hash<long long>{}(b);

			return h1 ^ (h2 << 1);

		}

	};

}
