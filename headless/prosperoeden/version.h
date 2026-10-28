// SPDX-License-Identifier: GPL-3.0-or-later
// The app version, as the launcher and the crash report show it. Its one home is
// sce_sys/param.json (contentVersion): the build writes app_version.h from that file
// (headless/CMakeLists.txt), and the package carries the same file.
#pragma once

#include <string>

#include "app_version.h"

namespace Eden {
inline constexpr const char* kAppVersion = EDEN_APP_VERSION;
// A build that is not a release: its branch and commit ("fix/x@8a221dc", "+dirty" with changes not
// committed), empty for a release (tools/build-headless-native.sh). Shown beside the version and
// never in it: the update check and launcher packs compare the version itself.
inline constexpr const char* kBuildLabel = EDEN_BUILD_LABEL;

// The version with the label, for the logs and the crash report: "01.005.000 private fix/x@8a221dc".
inline std::string LabelledVersion() {
    return kBuildLabel[0] ? std::string(kAppVersion) + " private " + kBuildLabel : std::string(kAppVersion);
}
}
