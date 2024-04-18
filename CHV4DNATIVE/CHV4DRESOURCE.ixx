module;

#include <stdexcept>

#include <vector>

export module CHV4DNATIVE:CHV4DRESOURCE;

import CHV4DTENSOR;

export namespace CAD
{
	typedef enum CHV4D_OUTPUT_DISPLAY_MODE {
		CHV4D_OUTPUT_DISPLAY_UNKNOWN			= 0x0,
		CHV4D_OUTPUT_DISPLAY_PANEL				= 0x1,
		CHV4D_OUTPUT_DISPLAY_SIDE_BY_SIDE_3D	= 0x2,
		CHV4D_OUTPUT_DISPLAY_OVER_UNDER_3D		= 0x3,
		CHV4D_OUTPUT_DISPLAY_MONO_VR			= 0x4,
		CHV4D_OUTPUT_DISPLAY_STEREO_VR			= 0x5,
		CHV4D_OUTPUT_DISPLAY_360_VR				= 0x6
	} CHV4D_NON_LINEAR_PROJECTION;

	typedef enum CHV4D_PROJECTION_MODE {
		CHV4D_PROJECTION_UNKNOWN		= 0x0,
		CHV4D_PROJECTION_NORMAL			= 0x1,
		CHV4D_PROJECTION_ORTHOGRAPHIC	= 0x2,
		CHV4D_PROJECTION_FISH_EYE		= 0x3,
		CHV4D_PROJECTION_STEREOGRAPHIC	= 0x4,
		CHV4D_PROJECTION_EQUIDISTANT	= 0x5,
		CHV4D_PROJECTION_MERCATOR		= 0x6,
		CHV4D_PROJECTION_TRANSVERSE		= 0x7,
		CHV4D_PROJECTION_PANINNI		= 0x8,
		CHV4D_PROJECTION_PEIRCE			= 0x9,
		CHV4D_PROJECTION_AZIMUTHAL		= 0xA,
		CHV4D_PROJECTION_HAMMER_AITOFF	= 0xB,
	} CHV4D_PROJECTION_MODE;

	typedef struct CHV4D_DISPLAY_DESCRIPTION {
		size_t px;
		size_t py;
		size_t refresh;
		size_t near;
		size_t far;
		CHV4D_OUTPUT_DISPLAY_MODE display;
		CHV4D_PROJECTION_MODE projection;
	} CHV4D_DISPLAY_DESCRIPTION;

	class HV4DPOINT : public GeV::CHV4DFLOAT4 {};

	class HV4DTEXT : public GeV::CHV4DFLOAT4 {};

	class HV4DNORM : public GeV::CHV4DFLOAT4 {};

	class HV4DVERTEX
	{
	public:
		HV4DVERTEX() = default;

		HV4DVERTEX(HV4DPOINT point, HV4DTEXT text, HV4DNORM norm)
		{
			data[0][0] = point[0]; data[0][1] = point[1]; data[0][2] = point[2]; data[0][3] = point[3];
			data[1][0] = text[0]; data[1][1] = text[1]; data[1][2] = text[2]; data[1][3] = text[3];
			data[2][0] = norm[0]; data[2][1] = norm[1]; data[2][2] = norm[2]; data[2][3] = text[3];
		}

		HV4DVERTEX(HV4DVERTEX const& e) { *this = e; }

	public:
		inline void operator =(HV4DVERTEX const& e) { memcpy(this, &e, sizeof(HV4DVERTEX)); }

		inline bool operator ==(HV4DVERTEX const& e) const { return memcmp(data, e.data, sizeof(HV4DVERTEX)) != 0; }

		inline bool operator !=(HV4DVERTEX const& e) const { return memcmp(data, e.data, sizeof(HV4DVERTEX)) == 0; }

		inline HV4DVERTEX const operator ()() const { return *this; }

	public:
		inline GeV::CHV4DFLOAT4& operator [](size_t const& i) { return *(GeV::CHV4DFLOAT4*)&data[i][0]; };

		inline GeV::CHV4DFLOAT4 const POINT() const { return GeV::CHV4DFLOAT4{ data[0][0], data[0][1], data[0][2], data[0][3] }; }

		inline GeV::CHV4DFLOAT4 const TEXTURE() const { return GeV::CHV4DFLOAT4{ data[1][0], data[1][1], data[1][2], data[1][3] }; }

		inline GeV::CHV4DFLOAT4 const NORMAL() const { return GeV::CHV4DFLOAT4{ data[2][0], data[2][1], data[2][2], data[1][3] }; }

	private:
		GeV::CHV4DFLOAT data[3][4];

	};

	class HV4DFACE
	{
	public:
		HV4DFACE() = default;

		HV4DFACE(HV4DVERTEX A, HV4DVERTEX B, HV4DVERTEX C)
		{
			for (size_t i = 0; i < 3; i++)
			{
				for (size_t j = 0; j < 3; j++)
				{
					for (size_t k = 0; k < 3; k++)
					{
						switch (i)
						{
						case 0:	data[i][j][k] = A[j][k]; break;
						case 1:	data[i][j][k] = B[j][k]; break;
						case 2:	data[i][j][k] = C[j][k]; break;
						}

					}

				}

			}

		}

		HV4DFACE(HV4DFACE const& e) { *this = e; }

	public:
		inline void operator =(HV4DFACE const& e) { memcpy(this, &e, sizeof(HV4DFACE)); }

		inline bool operator ==(HV4DFACE const& e) const { return memcmp(data, e.data, sizeof(HV4DFACE)) != 0; }

		inline bool operator !=(HV4DFACE const& e) const { return memcmp(data, e.data, sizeof(HV4DFACE)) == 0; }

		inline HV4DFACE const operator ()() const { return *this; }

	public:
		inline HV4DVERTEX A() {
			return {
				HV4DPOINT{ GeV::CHV4DFLOAT4{  data[0][0][0], data[0][0][1], data[0][0][2], data[0][0][3] } },
				HV4DTEXT{  GeV::CHV4DFLOAT4{ data[0][1][0], data[0][1][1], data[0][1][2], data[0][1][3] } },
				HV4DNORM{  GeV::CHV4DFLOAT4{ data[0][2][0], data[0][2][1], data[0][2][2], data[0][2][3] } } };
		}

		inline HV4DVERTEX B() {
			return {
				HV4DPOINT{ GeV::CHV4DFLOAT4{  data[1][0][0], data[1][0][1], data[1][0][2], data[1][0][3] } },
				HV4DTEXT{  GeV::CHV4DFLOAT4{ data[1][1][0], data[1][1][1], data[1][1][2], data[1][1][3] } },
				HV4DNORM{  GeV::CHV4DFLOAT4{ data[1][2][0], data[1][2][1], data[1][2][2], data[1][2][3] } } };
		}

		inline HV4DVERTEX C() {
			return {
				HV4DPOINT{ GeV::CHV4DFLOAT4{  data[2][0][0], data[2][0][1], data[2][0][2], data[2][0][3] } },
				HV4DTEXT{  GeV::CHV4DFLOAT4{ data[2][1][0], data[2][1][1], data[2][1][2], data[2][1][3] } },
				HV4DNORM{  GeV::CHV4DFLOAT4{ data[2][2][0], data[2][2][1], data[2][2][2], data[2][2][3] } } };
		}

	private:
		GeV::CHV4DFLOAT data[3][3][4];

	};

	class uHV4D2CELL
	{
	public:
		uHV4D2CELL() = default;

		uHV4D2CELL(size_t top, size_t left, size_t bottom, size_t right)
		{
			if (bottom < top || left > right) throw std::invalid_argument{ "Malformed 2Cell." };

		}

	public:
		inline void operator =(uHV4D2CELL const& e)
		{
			if (std::get<0>(e.data) < std::get<1>(e.data) || std::get<2>(e.data) > std::get<3>(e.data))
			{
				throw std::invalid_argument{ "Malformed 2Cell." };

			}

		}

		bool AssertOnto(uHV4D2CELL const& parent) const
		{
			if (std::get<0>(data) >= std::get<0>(parent.data) && std::get<0>(data) <= std::get<1>(parent.data) ||
				std::get<1>(data) >= std::get<0>(parent.data) && std::get<1>(data) <= std::get<1>(parent.data) ||
				std::get<2>(data) >= std::get<2>(parent.data) && std::get<2>(data) <= std::get<3>(parent.data) ||
				std::get<3>(data) >= std::get<2>(parent.data) && std::get<3>(data) <= std::get<3>(parent.data))
			{
				return false;

			}
			else
			{
				return true;

			}

		}

		bool AssertNoOverlap(uHV4D2CELL const& lh) const
		{
			if (std::get<0>(data) >= std::get<0>(lh.data) && std::get<0>(data) <= std::get<1>(lh.data) ||
				std::get<1>(data) >= std::get<0>(lh.data) && std::get<1>(data) <= std::get<1>(lh.data) ||
				std::get<2>(data) >= std::get<2>(lh.data) && std::get<2>(data) <= std::get<3>(lh.data) ||
				std::get<3>(data) >= std::get<2>(lh.data) && std::get<3>(data) <= std::get<3>(lh.data))
			{
				return false;

			}
			else
			{
				return true;

			}

		}

		inline size_t Top() const { return std::get<0>(data); }

		inline size_t Left() const { return std::get<1>(data); }

		inline size_t Bottom() const { return std::get<2>(data); }

		inline size_t Right() const { return std::get<3>(data); }

	private:
		std::tuple<size_t, size_t, size_t, size_t> data;

	};

	class fHV4D2CELL
	{
	public:
		fHV4D2CELL() = default;

		fHV4D2CELL(GeV::CHV4DFLOAT top, GeV::CHV4DFLOAT left, GeV::CHV4DFLOAT bottom, GeV::CHV4DFLOAT right)
		{
			if (bottom < top || left > right) throw std::invalid_argument{ "Malformed 2Cell." };

		}

	public:
		inline void operator =(fHV4D2CELL const& e)
		{
			if (std::get<0>(e.data) < std::get<1>(e.data) ||
				std::get<2>(e.data) > std::get<3>(e.data))
				throw std::invalid_argument{ "Malformed 2Cell." };

		}

		bool AssertOnto(fHV4D2CELL const& parent) const
		{
			if (std::get<0>(data) >= std::get<0>(parent.data) && std::get<0>(data) <= std::get<1>(parent.data) ||
				std::get<1>(data) >= std::get<0>(parent.data) && std::get<1>(data) <= std::get<1>(parent.data) ||
				std::get<2>(data) >= std::get<2>(parent.data) && std::get<2>(data) <= std::get<3>(parent.data) ||
				std::get<3>(data) >= std::get<2>(parent.data) && std::get<3>(data) <= std::get<3>(parent.data))
			{
				return false;

			}
			else
			{
				return true;

			}

		}

		bool AssertNoOverlap(fHV4D2CELL const& lh)
		{
			if (std::get<0>(data) >= std::get<0>(lh.data) && std::get<0>(data) <= std::get<1>(lh.data) ||
				std::get<1>(data) >= std::get<0>(lh.data) && std::get<1>(data) <= std::get<1>(lh.data) ||
				std::get<2>(data) >= std::get<2>(lh.data) && std::get<2>(data) <= std::get<3>(lh.data) ||
				std::get<3>(data) >= std::get<2>(lh.data) && std::get<3>(data) <= std::get<3>(lh.data))
			{
				return false;

			}
			else
			{
				return true;

			}

		}

		inline GeV::CHV4DFLOAT x() { return std::get<0>(data); }

		inline GeV::CHV4DFLOAT y() { return std::get<1>(data); }

		inline GeV::CHV4DFLOAT u() { return std::get<2>(data); }

		inline GeV::CHV4DFLOAT v() { return std::get<3>(data); }

	private:
		std::tuple<GeV::CHV4DFLOAT, GeV::CHV4DFLOAT, GeV::CHV4DFLOAT, GeV::CHV4DFLOAT> data;

	};

}