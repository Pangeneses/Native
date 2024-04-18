module;

#include <string>

#include <algorithm>
#include <iterator>
#include <vector>

#include <stdexcept>

module CTURI:CURIZIP;

namespace CTURI
{
	CURIZIP::CURIZIP()
	{

		return;

	}

	CURIZIP::CURIZIP(std::string const& uri)
	{
		tagURI = uri;

		try
		{
			IsValidURI();

		}
		catch (std::domain_error)
		{
			tagURI.clear();

			throw std::invalid_argument("");

		}

		return;

	}

	CURIZIP::CURIZIP(CURIZIP const& uri)
	{
		tagURI = uri.tagURI;

		return;

	}

	void CURIZIP::IsValidURI()
	{
		if (tagURI.size() > 255)
		{
			throw std::domain_error("");

		}

		std::vector<char>::iterator character{};

		for (std::string::iterator itt = tagURI.begin(); itt != tagURI.end(); itt++)
		{
			character = std::find(HV4DURIASCII.begin(), HV4DURIASCII.end(), *itt);

			if (character == HV4DURIASCII.end())
			{
				throw std::domain_error("");

			}

		}

		std::string schema = "file:///";

		if (!schema.compare(0, 7, tagURI)) throw std::invalid_argument{ "Incorrect schema." };

		size_t end_of_server = 8;

		if (schema.compare(0, 8, tagURI))
		{
			end_of_server = tagURI.find_first_of('/', 8);

			resource.server = tagURI.substr(9, end_of_server - 1);

		}
		else resource.server = "localhost";

		size_t end_of_path = tagURI.find_last_of('/');

		if (tagURI.substr(end_of_server + 1, 3)[1] == ':')
		{
			resource.drive = tagURI.substr(end_of_server + 1, 1);

			resource.path = tagURI.substr(end_of_server + 3, end_of_path);

		}
		else
		{
			resource.path = tagURI.substr(end_of_server, end_of_path);

		}

		size_t begin_of_fragment = tagURI.find_last_of('#');

		if (begin_of_fragment == std::string::npos)
		{
			resource.file = tagURI.substr(end_of_path + 1);

			resource.fragment = "";

		}
		else
		{
			resource.file = tagURI.substr(end_of_path + 1, begin_of_fragment - 1);

			resource.fragment = tagURI.substr(begin_of_fragment + 1);

		}

		if (resource.server.find_first_of(':') != std::string::npos)
		{
			resource.user = resource.server.substr(0, resource.server.find_first_of(':') - 1);

			if (resource.server.find_first_of('@') != std::string::npos)
			{
				resource.password = resource.server.substr(resource.server.find_first_of(':') + 1,
					resource.server.find_first_of('@') - resource.server.find_first_of(':') - 1);

				resource.server = resource.server.substr(resource.server.find_first_of('@') + 1);

			}
			else
			{
				throw std::invalid_argument{ "Improperly configured username:password@server" };

			}

		}

		return;

	}

	void CURIZIP::operator = (std::string const& uri)
	{
		tagURI = uri;

		try
		{
			IsValidURI();

		}
		catch (std::domain_error)
		{
			tagURI.clear();

			throw std::invalid_argument("");

		}

		return;

	}

	void CURIZIP::operator = (CURIZIP const& uri)
	{
		tagURI = uri.tagURI;

		return;

	}

	bool CURIZIP::operator == (std::string const& uri) const
	{
		CURIZIP var{};

		try
		{
			var = uri;

		}
		catch (std::domain_error)
		{
			throw std::invalid_argument("");

		}

		return *this == var;

	}

	bool CURIZIP::operator == (CURIZIP const& uri) const
	{
		return tagURI.compare(uri.tagURI) == 0;

	}

	std::string CURIZIP::operator()() const
	{
		return tagURI;

	}

	CTURI::SURIZIP CURIZIP::GetResource() const
	{
		return resource;

	}

}