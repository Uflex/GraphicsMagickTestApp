#include <iostream>
#include <Magick++.h>
#include "lcms2.h"
#include <exception>

int main(int /*argc*/, char *argv[])
{
    try
    {
        Magick::InitializeMagick(*argv);
        Magick::Image magickImage("AdobeRGB.jpg");

        Magick::Blob blob;
        magickImage.write(&blob, "PNG");

        // Getting the embedded color profile and display its name
        const Magick::Blob embeddedProfileBlob = magickImage.iccColorProfile();
        const size_t length = embeddedProfileBlob.length();
        if (length > 0) {
            const cmsHPROFILE embeddedProfile = cmsOpenProfileFromMem(
                embeddedProfileBlob.data(), static_cast<int>(length));
            wchar_t profileDesc[1000];
            cmsGetProfileInfo(embeddedProfile, cmsInfoDescription, "en", "US",
                              profileDesc, 1000);
            std::wcout << "Embedded Profile detected: " << profileDesc
                       << std::endl;
            cmsCloseProfile(embeddedProfile);
        } else {
            std::cout << "The image doesn't contain a color profile"
                      << std::endl;
        }
    }
    catch (std::exception &error)
    {
        std::cout << "exception: " << error.what() << std::endl;
    }

    return 0;
}
