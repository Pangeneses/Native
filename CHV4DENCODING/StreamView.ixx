module;

#include <string>
#include <vector>

export module CHV4DENCODE:StreamView;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :Decoder;
import :Encoder;

export namespace CHV4DENCODE
{
	class StreamView
	{
	public:
		StreamView() = default;

	public:
		int SetSream(
			Buffer const& buf,
			ENCODING const& encoding, 
			ENDIANNESS const& endianness);

		int LoadWatchword(Watchword const& watchWords);

	public:
		Text operator ()(size_t const& from, size_t const& to);

		Codepoint operator [](size_t const& at);

		Codepoint operator --(int);
		Codepoint operator ++(int);
		Codepoint operator -=(Codepoint const& rh);
		Codepoint operator +=(Codepoint const& rh);

		void operator ()(Codepoint codepoint);
		Codepoint operator ()();
		void operator !();

		StreamViewHash& operator->*(size_t N);

		Buffer const& operator->();

	private:
		ENCODING sourceEncoding;

		ENDIANNESS byteWise;

		Buffer sBuffer{};

		Text text{};

		std::list<Scan> streamInterface;

		StreamViewHash streamViewHash{};

		IndexedWatchwords indexedWatchwords;

		Scan scan{};

		size_t index{ 0 };

		size_t N{ 0 };

		Decoder characterDecoder{};

		Encoder characterEncoder{};

	};

}