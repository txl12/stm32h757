#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
    #include "lvgl.h"
#else
    #include "lvgl.h"
#endif

#if LV_USE_DEMO_MULTILANG

#ifndef LV_ATTRIBUTE_MEM_ALIGN
    #define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMAGE_IMG_EMOJI_MOVIE_CAMERA
    #define LV_ATTRIBUTE_IMAGE_IMG_EMOJI_MOVIE_CAMERA
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMAGE_IMG_EMOJI_MOVIE_CAMERA uint8_t
img_emoji_movie_camera_map[] = {
    0xff, 0xff, 0xff, 0xff, 0xf9, 0xf9, 0xf9, 0xff, 0xf3, 0xf3, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xfb, 0xfb, 0xff, 0xe5, 0xe5, 0xe5, 0xff, 0xd9, 0xd9, 0xd9, 0xff, 0xe0, 0xe0, 0xe0, 0xff, 0xfa, 0xfa, 0xfa, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xeb, 0xeb, 0xeb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf7, 0xf7, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xca, 0xca, 0xca, 0xff, 0x86, 0x86, 0x86, 0xff, 0x55, 0x55, 0x55, 0xff, 0x48, 0x48, 0x48, 0xff, 0x55, 0x55, 0x55, 0xff, 0x76, 0x76, 0x76, 0xff, 0xb9, 0xb9, 0xb9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xfa, 0xfa, 0xfa, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xf9, 0xf9, 0xf9, 0xff,
    0xf2, 0xf2, 0xf2, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xdf, 0xdf, 0xff, 0x6e, 0x6e, 0x6e, 0xff, 0x4b, 0x4b, 0x4b, 0xff, 0x39, 0x39, 0x39, 0xff, 0x3d, 0x3d, 0x3d, 0xff, 0x43, 0x43, 0x43, 0xff, 0x3c, 0x3c, 0x3c, 0xff, 0x6f, 0x6f, 0x6f, 0xff, 0xbc, 0xbc, 0xbc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf6, 0xf6, 0xf6, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfa, 0xfa, 0xfa, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8b, 0x8b, 0x8b, 0xff, 0x3c, 0x3c, 0x3c, 0xff, 0x49, 0x49, 0x49, 0xff, 0x52, 0x52, 0x52, 0xff, 0x5b, 0x5b, 0x5b, 0xff, 0x50, 0x50, 0x50, 0xff, 0x49, 0x49, 0x49, 0xff, 0x3d, 0x3d, 0x3d, 0xff, 0x61, 0x61, 0x61, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf5, 0xf5, 0xf5, 0xff, 0xe2, 0xe2, 0xe2, 0xff, 0xd6, 0xd6, 0xd6, 0xff, 0xef, 0xef, 0xef, 0xff, 0xf3, 0xf3, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xfb, 0xfb, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0x55, 0x55, 0x55, 0xff, 0x48, 0x48, 0x48, 0xff, 0x52, 0x52, 0x52, 0xff, 0x4e, 0x4e, 0x4e, 0xff, 0x55, 0x55, 0x55, 0xff, 0x4c, 0x4c, 0x4c, 0xff, 0x5c, 0x5c, 0x5c, 0xff, 0x3f, 0x3f, 0x3f, 0xff, 0x49, 0x49, 0x49, 0xff, 0xcb, 0xcb, 0xcb, 0xff, 0x82, 0x82, 0x82, 0xff, 0x50, 0x50, 0x50, 0xff, 0x39, 0x39, 0x39, 0xff, 0x4b, 0x4b, 0x4b, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xf0, 0xf0, 0xf0, 0xff,
    0xfd, 0xfd, 0xfd, 0xff, 0xf9, 0xf9, 0xf9, 0xff, 0x3d, 0x3d, 0x3d, 0xff, 0x4e, 0x4e, 0x4e, 0xff, 0x54, 0x54, 0x54, 0xff, 0x57, 0x57, 0x57, 0xff, 0x5f, 0x5f, 0x5f, 0xff, 0x5f, 0x5f, 0x5f, 0xff, 0x4a, 0x4a, 0x4a, 0xff, 0x40, 0x40, 0x40, 0xff, 0x57, 0x57, 0x57, 0xff, 0x71, 0x71, 0x71, 0xff, 0x4f, 0x4f, 0x4f, 0xff, 0x47, 0x47, 0x47, 0xff, 0x57, 0x57, 0x57, 0xff, 0x43, 0x43, 0x43, 0xff, 0x54, 0x54, 0x54, 0xff, 0xbd, 0xbd, 0xbd, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xf8, 0xf8, 0xf8, 0xff, 0x59, 0x59, 0x59, 0xff, 0x41, 0x41, 0x41, 0xff, 0x41, 0x41, 0x41, 0xff, 0x57, 0x57, 0x57, 0xff, 0x54, 0x54, 0x54, 0xff, 0x54, 0x54, 0x54, 0xff, 0x52, 0x52, 0x52, 0xff, 0x44, 0x44, 0x44, 0xff, 0x57, 0x57, 0x57, 0xff, 0x40, 0x40, 0x40, 0xff, 0x3d, 0x3d, 0x3d, 0xff, 0x5a, 0x5a, 0x5a, 0xff, 0x6c, 0x6c, 0x6c, 0xff, 0x4e, 0x4e, 0x4e, 0xff, 0x3f, 0x3f, 0x3f, 0xff, 0x9c, 0x9c, 0x9c, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xf8, 0xf8, 0xf8, 0xff, 0x9a, 0x9a, 0x9a, 0xff, 0x4f, 0x4f, 0x4f, 0xff, 0x40, 0x40, 0x40, 0xff, 0x5b, 0x5b, 0x5b, 0xff, 0x4d, 0x4d, 0x4d, 0xff, 0x51, 0x51, 0x51, 0xff, 0x4b, 0x4b, 0x4b, 0xff, 0x3b, 0x3b, 0x3b, 0xff, 0x51, 0x51, 0x51, 0xff, 0x5b, 0x5b, 0x5b, 0xff, 0x44, 0x44, 0x44, 0xff, 0x5e, 0x5e, 0x5e, 0xff, 0x53, 0x53, 0x53, 0xff, 0x5b, 0x5b, 0x5b, 0xff, 0x45, 0x45, 0x45, 0xff, 0x99, 0x99, 0x99, 0xff,
    0xff, 0xfb, 0xfc, 0xff, 0xff, 0xfc, 0xfd, 0xff, 0xef, 0xef, 0xef, 0xff, 0x5d, 0x62, 0x61, 0xff, 0x4e, 0x50, 0x50, 0xff, 0x45, 0x43, 0x43, 0xff, 0x44, 0x3c, 0x3d, 0xff, 0x54, 0x47, 0x49, 0xff, 0x48, 0x48, 0x48, 0xff, 0x47, 0x47, 0x47, 0xff, 0x46, 0x46, 0x46, 0xff, 0x47, 0x47, 0x47, 0xff, 0x48, 0x48, 0x48, 0xff, 0x47, 0x47, 0x47, 0xff, 0x42, 0x42, 0x42, 0xff, 0x3e, 0x3e, 0x3e, 0xff, 0x4d, 0x4d, 0x4d, 0xff, 0xcc, 0xcc, 0xcc, 0xff,
    0xef, 0xe9, 0xea, 0xff, 0xab, 0xa6, 0xa7, 0xff, 0xd5, 0xd5, 0xd5, 0xff, 0xea, 0xef, 0xee, 0xff, 0x7c, 0x7e, 0x7e, 0xff, 0x5f, 0x5d, 0x5d, 0xff, 0x4c, 0x46, 0x47, 0xff, 0x5f, 0x54, 0x56, 0xff, 0x66, 0x66, 0x66, 0xff, 0x51, 0x51, 0x51, 0xff, 0x41, 0x41, 0x41, 0xff, 0x41, 0x41, 0x41, 0xff, 0x45, 0x45, 0x45, 0xff, 0x49, 0x49, 0x49, 0xff, 0x58, 0x58, 0x58, 0xff, 0x6a, 0x6a, 0x6a, 0xff, 0xbe, 0xbe, 0xbe, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x93, 0x8d, 0x8e, 0xff, 0x4c, 0x47, 0x48, 0xff, 0x53, 0x53, 0x53, 0xff, 0xd1, 0xd3, 0xd3, 0xff, 0xf9, 0xfb, 0xfb, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0x86, 0x81, 0x82, 0xff, 0x62, 0x5c, 0x5d, 0xff, 0x67, 0x67, 0x67, 0xff, 0x50, 0x50, 0x50, 0xff, 0x45, 0x45, 0x45, 0xff, 0x50, 0x50, 0x50, 0xff, 0x54, 0x54, 0x54, 0xff, 0x50, 0x50, 0x50, 0xff, 0x5c, 0x5c, 0x5c, 0xff, 0x73, 0x73, 0x73, 0xff, 0xf4, 0xf4, 0xf4, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x6d, 0x68, 0x69, 0xff, 0x5f, 0x5d, 0x5d, 0xff, 0x45, 0x43, 0x43, 0xff, 0x6a, 0x6a, 0x6a, 0xff, 0xe9, 0xeb, 0xeb, 0xff, 0xd9, 0xdb, 0xdb, 0xff, 0x63, 0x63, 0x63, 0xff, 0x49, 0x49, 0x49, 0xff, 0x54, 0x54, 0x54, 0xff, 0x4b, 0x4b, 0x4b, 0xff, 0x4c, 0x4c, 0x4c, 0xff, 0x57, 0x57, 0x57, 0xff, 0x59, 0x59, 0x59, 0xff, 0x51, 0x51, 0x51, 0xff, 0x50, 0x50, 0x50, 0xff, 0x59, 0x59, 0x59, 0xff, 0x79, 0x79, 0x79, 0xff, 0x81, 0x81, 0x81, 0xff,
    0x7f, 0x7d, 0x7d, 0xff, 0x5d, 0x5b, 0x5b, 0xff, 0x5d, 0x5b, 0x5b, 0xff, 0x4d, 0x4b, 0x4b, 0xff, 0x70, 0x70, 0x70, 0xff, 0x4a, 0x4c, 0x4c, 0xff, 0x41, 0x46, 0x45, 0xff, 0x48, 0x4e, 0x4d, 0xff, 0x4c, 0x4c, 0x4c, 0xff, 0x4e, 0x4e, 0x4e, 0xff, 0x4d, 0x4d, 0x4d, 0xff, 0x48, 0x48, 0x48, 0xff, 0x47, 0x47, 0x47, 0xff, 0x4c, 0x4c, 0x4c, 0xff, 0x4f, 0x4f, 0x4f, 0xff, 0x4e, 0x4e, 0x4e, 0xff, 0x6d, 0x6d, 0x6d, 0xff, 0x74, 0x74, 0x74, 0xff,
    0x74, 0x74, 0x74, 0xff, 0x47, 0x45, 0x45, 0xff, 0x46, 0x41, 0x42, 0xff, 0x57, 0x52, 0x53, 0xff, 0x51, 0x51, 0x51, 0xff, 0x4c, 0x51, 0x50, 0xff, 0x4f, 0x57, 0x56, 0xff, 0x40, 0x4d, 0x4b, 0xff, 0x43, 0x43, 0x43, 0xff, 0x4e, 0x4e, 0x4e, 0xff, 0x4f, 0x4f, 0x4f, 0xff, 0x45, 0x45, 0x45, 0xff, 0x45, 0x45, 0x45, 0xff, 0x4f, 0x4f, 0x4f, 0xff, 0x51, 0x51, 0x51, 0xff, 0x4a, 0x4a, 0x4a, 0xff, 0xcc, 0xcc, 0xcc, 0xff, 0xcb, 0xcb, 0xcb, 0xff,
    0x71, 0x71, 0x71, 0xff, 0x6a, 0x68, 0x68, 0xff, 0x57, 0x52, 0x53, 0xff, 0x69, 0x64, 0x65, 0xff, 0x5e, 0x5c, 0x5c, 0xff, 0x53, 0x58, 0x57, 0xff, 0x37, 0x44, 0x42, 0xff, 0x2f, 0x40, 0x3d, 0xff, 0x3f, 0x3f, 0x3f, 0xff, 0x47, 0x47, 0x47, 0xff, 0x4d, 0x4d, 0x4d, 0xff, 0x4d, 0x4d, 0x4d, 0xff, 0x4c, 0x4c, 0x4c, 0xff, 0x4d, 0x4d, 0x4d, 0xff, 0x4b, 0x4b, 0x4b, 0xff, 0x48, 0x48, 0x48, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x79, 0x7b, 0x7b, 0xff, 0x50, 0x4e, 0x4e, 0xff, 0x44, 0x3f, 0x40, 0xff, 0x62, 0x5d, 0x5e, 0xff, 0x5f, 0x5d, 0x5d, 0xff, 0x41, 0x47, 0x46, 0xff, 0x47, 0x54, 0x52, 0xff, 0x51, 0x64, 0x61, 0xff, 0x4c, 0x4c, 0x4c, 0xff, 0x46, 0x46, 0x46, 0xff, 0x45, 0x45, 0x45, 0xff, 0x47, 0x47, 0x47, 0xff, 0x45, 0x45, 0x45, 0xff, 0x40, 0x40, 0x40, 0xff, 0x46, 0x46, 0x46, 0xff, 0x51, 0x51, 0x51, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xfd, 0xfd, 0xfd, 0xff,
    0x7f, 0x7f, 0x7f, 0xff, 0x58, 0x58, 0x58, 0xff, 0x34, 0x34, 0x34, 0xff, 0x81, 0x81, 0x81, 0xff, 0xec, 0xec, 0xec, 0xff, 0xe5, 0xe5, 0xe5, 0xff, 0x6a, 0x6a, 0x6a, 0xff, 0x4f, 0x4f, 0x4f, 0xff, 0x52, 0x52, 0x52, 0xff, 0x4b, 0x4b, 0x4b, 0xff, 0x49, 0x49, 0x49, 0xff, 0x4c, 0x4c, 0x4c, 0xff, 0x49, 0x49, 0x49, 0xff, 0x44, 0x44, 0x44, 0xff, 0x4d, 0x4d, 0x4d, 0xff, 0x5d, 0x5d, 0x5d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x79, 0x79, 0x79, 0xff, 0x58, 0x58, 0x58, 0xff, 0x67, 0x67, 0x67, 0xff, 0xc3, 0xc3, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xf7, 0xf7, 0xff, 0x98, 0x98, 0x98, 0xff, 0x72, 0x72, 0x72, 0xff, 0x6f, 0x6f, 0x6f, 0xff, 0x6a, 0x6a, 0x6a, 0xff, 0x6c, 0x6c, 0x6c, 0xff, 0x73, 0x73, 0x73, 0xff, 0x74, 0x74, 0x74, 0xff, 0x72, 0x72, 0x72, 0xff, 0x7c, 0x7c, 0x7c, 0xff, 0x8c, 0x8c, 0x8c, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xef, 0xef, 0xef, 0xff, 0xb4, 0xb4, 0xb4, 0xff, 0xc5, 0xc5, 0xc5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xf9, 0xf9, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xf9, 0xf9, 0xf9, 0xff, 0xfb, 0xfb, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfa, 0xfa, 0xfa, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
};

const lv_image_dsc_t img_emoji_movie_camera = {
    .header.cf = LV_COLOR_FORMAT_ARGB8888,
    .header.w = 18,
    .header.h = 19,
    .header.stride = 72,
    .data = img_emoji_movie_camera_map,
    .data_size = sizeof(img_emoji_movie_camera_map),
};

#endif
