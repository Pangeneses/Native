module;

#include <string>

#include <algorithm>
#include <iterator>
#include <vector>

#include <stdexcept>

export module CTURI:CURIZIP;

export namespace CTURI
{
	typedef struct SURIZIP {
		std::string server		{ '\0' };
		std::string user		{ '\0' };
		std::string password	{ '\0' };
		std::string drive		{ '\0' };
		std::string path		{ '\0' };
		std::string file		{ '\0' };
		std::string fragment	{ '\0' };
	} tagSURIZIP;

	class CURIZIP
	{
	public:
		CURIZIP();

		CURIZIP(std::string const& uri);

		CURIZIP(CURIZIP const& uri);

	private:
		void IsValidURI();

		SURIZIP resource{};

	public:
		void operator = (std::string const& uri);

		void operator = (CURIZIP const& uri);

		bool operator == (std::string const& uri) const;

		bool operator == (CURIZIP const& uri) const;

		std::string operator()() const;

		CTURI::SURIZIP GetResource() const;

	private:
		std::string tagURI{ '\0' };

	private:
		std::vector<char> HV4DURIASCII = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
			'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D',
			'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
			'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', '/', '?', '#',
			'[', ']', '@', '!', '$', '&', '\'', '(', ')', '*', '+', ',', ';', '=', '-', '.', '_', '~', '%' };

	};

}
