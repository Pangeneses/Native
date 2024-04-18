module;

#include <string>
#include <vector>

export module CHV4DPNG:CHV4DRESOURCE;

export namespace PNG 
{
    typedef enum CHV4DTPNG {
        HV4D_GREY               = 0,
        HV4D_RGB                = 2,
        HV4D_PALETTE            = 3,
        HV4D_GREY_ALPHA         = 4,
        HV4D_RGBA               = 6,
        HV4D_MAX_OCTET_VALUE    = 255
    } CHV4DTPNG;

    typedef struct CHV4DDECOPTIONS CHV4DDECOPTIONS;

    using CHV4DCUSTDECZ = uint32_t(
        unsigned char**, 
        size_t*, 
        const unsigned char*,
        size_t, 
        const CHV4DDECOPTIONS*);

    using CHV4DCUSTDECINFLATE = uint32_t(
        unsigned char**, 
        size_t*,
        const unsigned char*, 
        size_t,
        const CHV4DDECOPTIONS*);

    struct CHV4DDECOPTIONS {
        uint32_t IgnoreAdler32;
        uint32_t IgnoreNLen;
        size_t MaxOutSz;
        CHV4DCUSTDECZ CustomZ;
        CHV4DCUSTDECINFLATE CustomInf;
        const void* CustomContext;
    };

    typedef struct CHV4DCOMPOPTIONS CHV4DCOMPOPTIONS;
    
    using CHV4DCUSTCOMPZ = uint32_t(
        unsigned char**, 
        size_t*,
        const unsigned char*, 
        size_t,
        const CHV4DCOMPOPTIONS*);

    using CHV4DCUSTCOMPDEFLATE  = uint32_t(
        unsigned char**, 
        size_t*,
        const unsigned char*, 
        size_t,
        const CHV4DCOMPOPTIONS*);
    
    struct CHV4DCOMPOPTIONS {
        uint32_t BType;
        uint32_t UseLZ77;
        uint32_t WindowSz;
        uint32_t MinMatch;
        uint32_t NiceMatch;
        uint32_t LazyMatc;
        CHV4DCUSTCOMPZ CustomZ;
        CHV4DCUSTCOMPDEFLATE CustomDefl;
        const void* CustomContext;
    };
    
    typedef struct CHV4DPNGMODE {
        uint32_t CompressionMethod;
        uint32_t FilterMethod;
        uint32_t InterlaceMethod;
    } CHV4DPNGMODE;

    typedef struct CHV4DPNGCOLORMODE {
        CHV4DTPNG ColorType;
        uint32_t BitDepth;
        unsigned char* Palette;
        size_t PaletteSize;
        uint32_t KeyDefined;
        uint32_t KeyR;
        uint32_t KeyG;
        uint32_t KeyB;
    } CHV4DPNGCOLORMODE;

    typedef struct CHV4DPNGCHRONO {
        uint32_t TimeDefined;
        uint32_t YYYY;
        uint32_t MMM;
        uint32_t DD;
        uint32_t HH;
        uint32_t MM;
        uint32_t SS;
    } CHV4DPNGCHRONO;

    typedef struct CHV4DPNGPHYS {
        uint32_t PhysDefined;
        uint32_t PhysX;
        uint32_t PhysY;
        uint32_t PhysUnit;
    } CHV4DPNGPHYS;

    typedef struct CHV4DPNGBACKGROUND {
        uint32_t BackgroundDefined;
        uint32_t BackgroundR;
        uint32_t BackgroundG;
        uint32_t BackgroundB;
    } CHV4DPNGBACKGROUND;

    typedef struct CHV4DPNGTEXT {
        size_t TextNum;
        char** TextKeys;
        char** TextStrings;
    } CHV4DPNGTEXT;

    typedef struct CHV4DPNGFOREIGN {
        size_t InternTextNum;
        char** InternTextKeys;
        char** InternTextLangTags;
        char** InternTextTransKeys;
        char** InternTextStrings;
    } CHV4DPNGFOREIGN;

    typedef struct CHV4DPNGGAMMA {
        uint32_t GamaDefined;
        uint32_t GamaGamma;
    } CHV4DPNGGAMMA;

    typedef struct CHV4DPNGCHROMA {
        uint32_t ChrmDefined;
        uint32_t ChrmWhite_x;
        uint32_t ChrmWhite_y;
        uint32_t ChrmRedX;
        uint32_t ChrmRedY;
        uint32_t ChrmGreenX;
        uint32_t ChrmGreenY;
        uint32_t ChrmBlueX;
        uint32_t ChrmBlueY;
    } CHV4DPNGCHROMA;

    typedef struct CHV4DPNGICCP {
        uint32_t iCCPDefined;
        char* iCCPName;
        unsigned char* iCCPProfile;
        uint32_t iCCPProfileSz;
    } CHV4DPNGICCP;

    typedef struct CHV4DPNGSRGB {
        uint32_t sRGBDefined;
        uint32_t sRGBIntent;
        uint32_t sBitDefined;
        uint32_t sBitR;
        uint32_t sBitG;
        uint32_t sBitB;
        uint32_t sBitA;
    } CHV4DPNGSRGB;

    typedef struct CHV4DPNGUNKN {
        unsigned char* UnkChunkData[3];
        size_t UnkChunkSize[3];
    } CHV4DPNGUNKN;

    typedef struct CHV4DPNGINFO {
        CHV4DPNGMODE Mode;
        CHV4DPNGCOLORMODE Color;
        CHV4DPNGBACKGROUND Background;
        CHV4DPNGTEXT Text;
        CHV4DPNGFOREIGN foreign;
        CHV4DPNGCHRONO Time;
        CHV4DPNGPHYS pHYs;
        CHV4DPNGGAMMA Gamma;
        CHV4DPNGCHROMA Chroma;
        CHV4DPNGICCP iCCP;
        CHV4DPNGSRGB sRGB;
        CHV4DPNGUNKN UnkChunks;
    } CHV4DPNGINFO;

    typedef struct CHV4DDECODEROPT {
        CHV4DDECOPTIONS ZLibSettings;
        uint32_t IgnoreCRC;
        uint32_t IgnoreCritical;
        uint32_t IgnoreEnd;
        uint32_t ColorConvert;
        uint32_t ReadTextChunk;
        uint32_t RememberUnkChunk;
        size_t MaxICCSz;
    } CHV4DDECODEROPT;

    typedef enum CHV4DFILTERSTRATEGY {
        HV4D_LFS_ZERO           = 0,
        HV4D_LFS_ONE            = 1,
        HV4D_LFS_TWO            = 2,
        HV4D_LFS_THREE          = 3,
        HV4D_LFS_FOUR           = 4,
        HV4D_LFS_MINSUM         = 5,
        HV4D_LFS_ENTROPY        = 6,
        HV4D_LFS_BRUTE_FORCE    = 7,
        HV4D_LFS_PREDEFINED     = 8
    } CHV4DFILTERSTRATEGY;

    typedef struct CHV4DCOLORSTATS {
        uint32_t colored;
        uint32_t Key;
        uint16_t KeyR;
        uint16_t KeyG;
        uint16_t KeyB;
        uint32_t Alpha;
        uint32_t NumColors;
        unsigned char Palette[1024];
        uint32_t Bits;
        size_t NumPixels;
        uint32_t AllowPalette;
        uint32_t AllowGreyScale;
    } CHV4DCOLORSTATS;

    typedef struct CHV4DENCODEROPT {
        CHV4DCOMPOPTIONS zlibsettings;
        uint32_t AutoConvert;
        uint32_t FilterPaletteZero;
        CHV4DFILTERSTRATEGY FilterStrategy;
        const unsigned char* PredefinedFilters;
        uint32_t ForcePalette;
        uint32_t AddID;
        uint32_t TextCompression;
    } CHV4DENCODEROPT;

    typedef struct CHV4DPNGSTATE {
        CHV4DDECOPTIONS Decoder;
        CHV4DENCODEROPT Encoder;
        CHV4DPNGCOLORMODE InfoRaw;
        CHV4DPNGINFO InfoPNG;
        uint32_t Error;
    } CHV4DPNGSTATE;

}