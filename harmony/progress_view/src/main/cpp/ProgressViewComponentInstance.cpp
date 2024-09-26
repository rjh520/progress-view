#include "ProgressViewComponentInstance.h"
#include "Props.h"
#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

// 十进制整数转十六进制字符串
string DecimalToHex(int decimalColor) {
    stringstream ss;
    ss << hex << decimalColor;
    string hexColor = ss.str();
    return hexColor;
}
namespace rnoh {

ProgressViewComponentInstance::ProgressViewComponentInstance(Context context)
    : CppComponentInstance(std::move(context)) {}

ProgressViewNode &ProgressViewComponentInstance::getLocalRootArkUINode() { return m_progressNode; }

std::optional<std::string> ProgressViewComponentInstance::getTintColorFromDynamic(folly::dynamic value) {
    auto rawPropsColor =
        (value.count("progressTintColor") > 0) ? std::optional(value["progressTintColor"].asString()) : std::nullopt;
    return rawPropsColor;
}

void ProgressViewComponentInstance::onPropsChanged(SharedConcreteProps const &props) {
    CppComponentInstance::onPropsChanged(props);

    this->getLocalRootArkUINode().setProgress(props->progress);

    int type = 1;
    if (props->isIndeterminate) {
        type = 1;
        this->getLocalRootArkUINode().setIsIndeterminate(type);
    } else {
        type = 0;
        this->getLocalRootArkUINode().setIsIndeterminate(type);
    }
    //     DLOG(INFO) << "[FastImage] Props->isIndeterminate: " << props->isIndeterminate;
    if (props->rawProps != nullptr) {
        auto progressTintColor = getTintColorFromDynamic(props->rawProps);
        if (progressTintColor.has_value()) {
            uint32_t COLOR_ALPHA_MASK = std::stol(progressTintColor.value());
            this->getLocalRootArkUINode().setProgressTintColor(COLOR_ALPHA_MASK);
        }
    }
}

} // namespace rnoh
