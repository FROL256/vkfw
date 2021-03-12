#ifndef VK_SWAPCHAIN_H
#define VK_SWAPCHAIN_H

#include "vulkan_wrapper/vulkan_include.h"
#include <vector>
#include <cassert>
#include <array>

struct VulkanAttachment
{
  VkFormat format;
  VkImage image;
  VkImageView view;
};

struct SwapChainSupportDetails
{
  VkSurfaceCapabilitiesKHR capabilities;
  std::vector<VkSurfaceFormatKHR> formats;
  std::vector<VkPresentModeKHR> presentModes;
};

class VulkanSwapChain
{
public:

  //Create Swap chain and get associated presentation queue
  VkQueue CreateSwapChain(const VkPhysicalDevice &physicalDevice, const VkDevice &logicalDevice, VkSurfaceKHR &a_surface,
                          uint32_t &width, uint32_t &height, bool vsync = false, VkSurfaceTransformFlagsKHR& a_preTransform = m_dummy);

  static VkSurfaceFormatKHR ChooseSurfaceFormat(const std::vector<VkSurfaceFormatKHR> &availableFormats);

  static VkPresentModeKHR ChoosePresentMode(const std::vector<VkPresentModeKHR> &availablePresentModes, bool vsync);

  VkResult AcquireNextImage(VkSemaphore presentCompleteSemaphore, uint32_t *imageIndex);

  VkResult QueuePresent(VkQueue queue, uint32_t imageIndex, VkSemaphore waitSemaphore = VK_NULL_HANDLE);

  void Cleanup();

  VkFormat GetFormat() const {return m_colorFormat; }
  uint32_t GetImageCount() const {return m_imageCount; }
  VkExtent2D GetExtent() const {return m_swapchainExtent; }
  VulkanAttachment GetAttachment(uint32_t i) const { assert(i < m_imageCount); return m_attachments[i]; }

  std::array<float, 16> GetSurfaceMatrixArr() const {return m_surfaceMatrix; }
  const float* GetSurfaceMatrixPtr() const {return m_surfaceMatrix.data(); }

private:

  static constexpr float DEG_TO_RAD = float(3.14159265358979323846f) / 180.0f;
  std::array<float, 16> m_surfaceMatrix = {1.0f, 0.0f, 0.0, 0.0f,
                                           0.0f, 1.0f, 0.0, 0.0f,
                                           0.0f, 0.0f, 1.0, 0.0f,
                                           0.0f, 0.0f, 0.0, 1.0f}; // 4x4 matrix stored by columns
  VkSwapchainKHR m_swapChain = VK_NULL_HANDLE;
  static VkSurfaceTransformFlagsKHR  m_dummy;

  VkFormat m_colorFormat;
  uint32_t m_imageCount;
  VkExtent2D m_swapchainExtent {};
  VkColorSpaceKHR m_colorSpace;

  std::vector<VulkanAttachment> m_attachments;

  uint32_t m_queueGraphicsIndex = UINT32_MAX;
  uint32_t m_queuePresentIndex  = UINT32_MAX;

  VkSurfaceKHR m_surface = VK_NULL_HANDLE;
  VkDevice m_logicalDevice = VK_NULL_HANDLE;
  VkPhysicalDevice m_physicalDevice = VK_NULL_HANDLE;

  void Create(uint32_t &width, uint32_t &height, bool vsync = false, VkSurfaceTransformFlagsKHR& a_preTransform = m_dummy);

  void InitSurface(VkSurfaceKHR &a_surface);

};


#endif //VK_SWAPCHAIN_H
