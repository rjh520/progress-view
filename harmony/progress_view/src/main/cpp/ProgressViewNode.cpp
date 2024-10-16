#include "ProgressViewNode.h"
#include "RNOH/arkui/NativeNodeApi.h"
#include <iostream>
#include <cstring>

namespace rnoh {

ProgressViewNode::ProgressViewNode()
    : ArkUINode(NativeNodeApi::getInstance()->createNode(ArkUI_NodeType::ARKUI_NODE_PROGRESS)) {}

ProgressViewNode &ProgressViewNode::setProgress(facebook::react::Float val) {
    ArkUI_NumberValue value[] = {{.f32 = static_cast<float>(val * 100)}};
    ArkUI_AttributeItem item = {value, sizeof(value) / sizeof(ArkUI_NumberValue)};
    maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_PROGRESS_VALUE, &item));
    return *this;
}

ProgressViewNode &ProgressViewNode::setProgressTintColor(uint32_t val) {
    ArkUI_NumberValue color_array[] = {{.u32 = val}};
    ArkUI_AttributeItem item_color = {&color_array[0], 1};
    maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_PROGRESS_COLOR, &item_color));
    return *this;
}

ProgressViewNode &ProgressViewNode::setIsIndeterminate(int type) {
    ArkUI_NumberValue type_array[] = {{.i32 = ARKUI_PROGRESS_TYPE_LINEAR}, {.i32 = ARKUI_PROGRESS_TYPE_RING}};
    ArkUI_AttributeItem item_type = {&type_array[type], 1};
    maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_PROGRESS_TYPE, &item_type));
    return *this;
}
} // namespace rnoh
