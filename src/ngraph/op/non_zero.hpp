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

namespace ngraph
{
    namespace op
    {
        namespace v0
        {
            /// \brief NonZero operation.
            class NGRAPH_API NonZero : public Op
            {
            public:
                static constexpr NodeTypeInfo type_info{"NonZero", 0};
                const NodeTypeInfo& get_type_info() const override { return type_info; }
                /// \brief Constructs a NonZero operation.
                NonZero() = default;
                /// \brief Constructs a NonZero operation.
                ///
                /// \param arg Node that produces the input tensor.
                NonZero(const Output<Node>& arg);

                bool visit_attributes(AttributeVisitor& visitor) override;
                void validate_and_infer_types() override;

                virtual std::shared_ptr<Node>
                    copy_with_new_args(const NodeVector& new_args) const override;
            };
        }
        using v0::NonZero;
    } // namespace op
} // namespace ngraph