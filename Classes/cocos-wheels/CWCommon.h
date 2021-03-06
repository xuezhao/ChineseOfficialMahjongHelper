﻿#ifndef __CW_COMMON_H__
#define __CW_COMMON_H__

#include "cocos2d.h"
#include "../utils/compiler.h"

#define CREATE_FUNC_WITH_PARAM_1(class_name_, arg_type1_, arg1_)    \
static class_name_ *create(arg_type1_ arg1_) {              \
    class_name_ *ret = new (std::nothrow) class_name_();    \
    if (ret != nullptr && ret->init(                        \
        std::forward<arg_type1_>(arg1_))) {                 \
        ret->autorelease();                                 \
        return ret;                                         \
    }                                                       \
    else {                                                  \
        CC_SAFE_DELETE(ret);                                \
        return nullptr;                                     \
    }                                                       \
}

#define CREATE_FUNC_WITH_PARAM_2(class_name_, arg_type1_, arg1_,    \
    arg_type2_, arg2_)                                              \
static class_name_ *create(arg_type1_ arg1_, arg_type2_ arg2_) {    \
    class_name_ *ret = new (std::nothrow) class_name_();            \
    if (ret != nullptr && ret->init(                                \
        std::forward<arg_type1_>(arg1_),                            \
        std::forward<arg_type2_>(arg2_))) {                         \
        ret->autorelease();                                         \
        return ret;                                                 \
    }                                                               \
    else {                                                          \
        CC_SAFE_DELETE(ret);                                        \
        return nullptr;                                             \
    }                                                               \
}

#define CREATE_FUNC_WITH_PARAM_3(class_name_, arg_type1_, arg1_,                \
    arg_type2_, arg2_, arg_type3_, arg3_)                                       \
static class_name_ *create(arg_type1_ arg1_, arg_type2_ arg2_,                  \
    arg_type3_ arg3_) {                                                         \
    class_name_ *ret = new (std::nothrow) class_name_();                        \
    if (ret != nullptr && ret->init(std::forward<arg_type1_>(arg1_),            \
        std::forward<arg_type2_>(arg2_), std::forward<arg_type3_>(arg3_))) {    \
        ret->autorelease();                                                     \
        return ret;                                                             \
    }                                                                           \
    else {                                                                      \
        CC_SAFE_DELETE(ret);                                                    \
        return nullptr;                                                         \
    }                                                                           \
}

#define CREATE_FUNC_WITH_PARAM_4(class_name_, arg_type1_, arg1_,                \
    arg_type2_, arg2_, arg_type3_, arg3_, arg_type4_, arg4_)                    \
static class_name_ *create(arg_type1_ arg1_, arg_type2_ arg2_,                  \
    arg_type3_ arg3_, arg_type4_ arg4_) {                                       \
    class_name_ *ret = new (std::nothrow) class_name_();                        \
    if (ret != nullptr && ret->init(std::forward<arg_type1_>(arg1_),            \
        std::forward<arg_type2_>(arg2_), std::forward<arg_type3_>(arg3_),       \
        std::forward<arg_type4_>(arg4_))) {                                     \
        ret->autorelease();                                                     \
        return ret;                                                             \
    }                                                                           \
    else {                                                                      \
        CC_SAFE_DELETE(ret);                                                    \
        return nullptr;                                                         \
    }                                                                           \
}

#define CREATE_FUNC_WITH_PARAM_5(class_name_, arg_type1_, arg1_,                \
    arg_type2_, arg2_, arg_type3_, arg3_, arg_type4_, arg4_, arg_type5_, arg5_) \
static class_name_ *create(arg_type1_ arg1_, arg_type2_ arg2_,                  \
    arg_type3_ arg3_, arg_type4_ arg4_, arg_type5_ arg5_) {                     \
    class_name_ *ret = new (std::nothrow) class_name_();                        \
    if (ret != nullptr && ret->init(std::forward<arg_type1_>(arg1_),            \
        std::forward<arg_type2_>(arg2_), std::forward<arg_type3_>(arg3_),       \
        std::forward<arg_type4_>(arg4_), std::forward<arg_type5_>(arg5_))) {    \
        ret->autorelease();                                                     \
        return ret;                                                             \
    }                                                                           \
    else {                                                                      \
        CC_SAFE_DELETE(ret);                                                    \
        return nullptr;                                                         \
    }                                                                           \
}

namespace cw {

void scaleLabelToFitWidth(cocos2d::Label *label, float width);
void trimLabelStringWithEllipsisToFitWidth(cocos2d::Label *label, float width);

void calculateColumnsCenterX(const float *colWidth, size_t col, float *xPos);

std::string getClipboardText();
void setClipboardText(const char *text);

}

#endif
