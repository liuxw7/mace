//
// Copyright (c) 2017 XiaoMi All rights reserved.
//

#ifndef MACE_CORE_RUNTIME_OPENCL_OPENCL_ALLOCATOR_H_
#define MACE_CORE_RUNTIME_OPENCL_OPENCL_ALLOCATOR_H_

#include <vector>

#include "mace/core/allocator.h"

namespace mace {

class OpenCLAllocator : public Allocator {
 public:
  OpenCLAllocator();

  ~OpenCLAllocator() override;

  MaceStatus New(size_t nbytes, void **result) const override;

  /*
   * Use Image2D with RGBA (128-bit) format to represent the image.
   *
   * @ shape : [depth, ..., height, width ].
   */
  MaceStatus NewImage(const std::vector<size_t> &image_shape,
                      const DataType dt,
                      void **result) const override;

  void Delete(void *buffer) const override;

  void DeleteImage(void *buffer) const override;

  void *Map(void *buffer, size_t offset, size_t nbytes) const override;

  void *MapImage(void *buffer,
                 const std::vector<size_t> &image_shape,
                 std::vector<size_t> *mapped_image_pitch) const override;

  void Unmap(void *buffer, void *mapped_ptr) const override;

  bool OnHost() const override;
};

}  // namespace mace

#endif  // MACE_CORE_RUNTIME_OPENCL_OPENCL_ALLOCATOR_H_
