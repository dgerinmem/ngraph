//*****************************************************************************
// Copyright 2017-2020 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//*****************************************************************************

#pragma once

#include "ngraph/op/op.hpp"
#include "ngraph/op/util/scatter.hpp"

namespace ngraph
{
    namespace op
    {
        namespace v3
        {
            /// \brief Set new values to slices from inputs addressed by indices
            class NGRAPH_API ScatterElementsUpdate : public util::Scatter
            {
            public:
                static constexpr NodeTypeInfo type_info{"ScatterElementsUpdate", 3};
                const NodeTypeInfo& get_type_info() const override { return type_info; }
                ScatterElementsUpdate() = default;
                /// \param inputs Tensor
                /// \param indices Index tensor: Data type must be `element::i32` or `element::i64`
                /// \param updates Tensor: Must have same type as inputs
                ScatterElementsUpdate(const Output<Node>& inputs,
                                      const Output<Node>& indices,
                                      const Output<Node>& updates,
                                      const Output<Node>& axis);

                void generate_adjoints(autodiff::Adjoints& /* adjoints */,
                                       const OutputVector& /* deltas */) override
                {
                    throw ngraph_error("Not yet implemented");
                }

                virtual std::shared_ptr<Node>
                    copy_with_new_args(const NodeVector& new_args) const override;
                bool visit_attributes(AttributeVisitor& visitor) override;
            };
        }
        using v3::ScatterElementsUpdate;
    }
}