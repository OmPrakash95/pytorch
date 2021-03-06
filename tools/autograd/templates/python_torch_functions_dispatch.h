#pragma once

// ${generated_comment}

#include <ATen/ATen.h>
#include "torch/csrc/cuda/lazy_init.h"
#include "torch/csrc/utils/auto_gil.h"
#include "torch/csrc/utils/auto_gpu.h"
#include "torch/csrc/autograd/generated/VariableType.h"

// Contains inline wrappers around ATen functions that release the GIL and
// switch to the correct CUDA device.

extern at::Type* THPDefaultATenType;

namespace torch { namespace autograd {

using at::Tensor;
using at::Scalar;
using at::TensorList;
using at::IntList;
using at::Generator;
using at::SparseTensor;
using at::Storage;

static at::Type& default_type() {
  if (!THPDefaultATenType) {
    throw std::runtime_error("THPDefaultATenType not initialized");
  }
  return *VariableType::getType(*THPDefaultATenType);
}

static void maybe_initialize_cuda(const at::Type &type) {
  if (type.is_cuda()) {
    torch::cuda::lazy_init();
  }
}

${py_method_dispatch}

}} // namespace torch::autograd
