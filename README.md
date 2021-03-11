# vkfw
Thin Vulkan Helpers library. This library contain seperate helpers for different kind of tasks:

1. vk_utils.h/vk_utils.cpp -- Vulkan Initialization helpers and general purpose functions.
2. vk_buffer.h/vk_buffer.cpp -- Create buffers, assign them to memory.
3. vk_copy.h/vk_copy.cpp -- Copying data (CPU <=> GPU) interface and implementation.
4. vk_compute_pipeline.h/vk_compute_pipeline.cpp --- create compute pipelines from SPIR-V shaders.
5. vk_graphics_pipeline.h/vk_graphics_pipeline.cpp --- create graphics pipelines from SPIR-V shaders and states desc.
6. vk_program.h/vk_program.cpp -- create and manage descriptor sets by 'ProgramBindings' helper.
7. vk_texture.h/vk_texture.cpp -- working with textures, 'BaseTexture2D', 'RenderableTexture2D'.
8. vk_quad.h/vk_quad.cpp -- full screen quad ('FSQuad') and full screen triangle ('QuadRenderer').

# Acknowledgements

We sincerely thank Huawei for the great project during which this framework was created and for the special permittion to open source code of vkfw at early stage for the educational purposes which we got at 10.03.2021.

These source code was created during Moscow State University (MSU) and Huawei cooperation.
Under the terms of this cooperation 'vkfw' framework become open source after 28.12.2022.
However, Huawei allows to use that for educational and non-commercial purposes after 10.03.2021.
