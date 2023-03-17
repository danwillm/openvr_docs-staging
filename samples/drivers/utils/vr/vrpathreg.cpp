#include "vrpathreg.h"
#include "vrcore/vrpathregistry_public.h"

class VRPathRegInternal : public CVRPathRegistry_Public {
public:
    bool AddDriverPathToExternalDrivers(const std::string &driver_path) {
        //make sure driver isn't already in the list of external drivers
        auto i = std::find(m_vecExternalDrivers.begin(), m_vecExternalDrivers.end(), std::string(driver_path));
        if (i != m_vecExternalDrivers.end()) {
            return false;
        }

        m_vecExternalDrivers.push_back(driver_path);

        return true;
    }

    bool RemoveDriverPathFromExternalDrivers(const std::string &driver_path) {
        auto i = std::find(m_vecExternalDrivers.begin(), m_vecExternalDrivers.end(), driver_path);
        if (i != m_vecExternalDrivers.end()) {
            m_vecExternalDrivers.erase(i);

            return true;
        }

        return false;
    }
};

bool RegisterDriverWithRuntime(const std::string &driver_path) {
    VRPathRegInternal path_reg;
    path_reg.BLoadFromFile();

    if (!path_reg.AddDriverPathToExternalDrivers(driver_path)) {
        return false;
    }

    if (!path_reg.BSaveToFile()) {
        return false;
    }

    return true;
}

bool RemoveDriverFromRuntime(const std::string &driver_path) {
    VRPathRegInternal path_reg;
    path_reg.BLoadFromFile();

    if (!path_reg.RemoveDriverPathFromExternalDrivers(driver_path)) {
        return false;
    }

    if (!path_reg.BSaveToFile()) {
        return false;
    }

    return true;
}