module;

#include <string>
#include <vector>

#include <stdexcept>

module CHV4DENCODE:StreamView;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :Decoder;
import :Encoder;

namespace CHV4DENCODE
{
	int StreamView::SetSream(
		Buffer const& buf,
		ENCODING const& encoding,
		ENDIANNESS const& endianness)
	{
		sBuffer = buf;

		text = characterDecoder.ToCodepoints(sBuffer.data(), text.size(), encoding, endianness);

		scan = text.begin();

		sourceEncoding = encoding;

		byteWise = endianness;

		return 1;

	}

	int StreamView::LoadWatchword(Watchword const& watchWords)
	{
		for (std::u8string str : watchWords)
		{
			indexedWatchwords.insert({ str.c_str(), std::list<Scan*>{} });

		}

		return -1;

	}

	Text StreamView::operator ()(size_t const& from, size_t const& to)
	{
		if (text.size() < from || text.size() < to) throw std::invalid_argument{ "Reading outside of stream range." };

		return { std::next(text.begin(), from), std::next(text.begin(), to) };

	}

	Codepoint StreamView::operator [](size_t const& at)
	{
		scan = text.begin();

		if (std::distance(std::next(text.begin(), at), text.end()) < 0)
		{
			scan = text.begin();

			throw std::out_of_range{ "Beyond the ending of file." };

		}

		if (at == EOS)
		{
			scan = text.end();

		}

		return *std::next(text.begin(), at);

	}

	Codepoint StreamView::operator --(int)
	{
		if (std::distance(scan--, text.begin()) > 0)
		{
			scan = text.begin();

			throw std::out_of_range{ "Beyond the beginning of file." };

		}

		return *scan;

	}

	Codepoint StreamView::operator ++(int)
	{
		if (std::distance(scan++, text.end()) < 0)
		{
			scan = text.begin();

			throw std::out_of_range{ "Beyond the ending of file." };

		}

		return *scan;

	}

	Codepoint StreamView::operator -=(Codepoint const& rh)
	{
		if (std::distance(std::next(scan, rh), text.begin()) > 0)
		{
			scan = text.begin();

			throw std::out_of_range{ "Beyond the beginning of file." };

		}

		return *scan;

	}

	Codepoint StreamView::operator +=(Codepoint const& rh)
	{
		if (rh == EOS)
		{
			scan = text.end();

		}

		if (std::distance(std::next(scan, rh), text.end()) < 0)
		{
			scan = text.begin();

			throw std::out_of_range{ "Beyond the ending of file." };

		}

		return *scan;

	}

	void StreamView::operator()(Codepoint codepoint)
	{



	}

	Codepoint StreamView::operator()()
	{
		return *scan;

	}

	void StreamView::operator!()
	{


	}

	StreamViewHash& StreamView::operator->*(size_t resizeN)
	{
		if (N == resizeN) return streamViewHash;

		if (resizeN < N) { streamViewHash.resize(resizeN); return streamViewHash; }

		for (size_t n = N; n < resizeN; n++)
		{
			for (size_t i = 0; i < (text.size() - resizeN); i++)
			{
				scan = std::next(text.begin(), i);

				streamInterface.push_back(scan);

				Codepoint codepoint = *scan;

				try
				{
					streamViewHash[n].at(codepoint);

				}
				catch (std::out_of_range)
				{
					streamViewHash[n].insert({ codepoint, ScanPoints{} });

				}

				streamViewHash[n].at(codepoint).push_front(&streamInterface.back());

				ScanPoints::iterator itt;

				ScanPoints* scanPoints = &streamViewHash[n].at(codepoint);

				for (itt = scanPoints->begin(); std::distance(itt, scanPoints->end()) > 1; itt++)
				{
					if (std::distance(*itt, std::next(*itt, 1))) std::swap(*itt, *(itt++));

				}

			}

		}

		return streamViewHash;

	}

	Buffer const& StreamView::operator->()
	{
		return sBuffer;

	}

}