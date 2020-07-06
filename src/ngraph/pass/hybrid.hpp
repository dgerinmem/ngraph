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

#include <memory>
#include <set>
#include <vector>

#include "ngraph/pass/pass.hpp"

namespace ngraph
{
            namespace pass
            {
                class Hybrid;
            }
}

class ngraph::pass::Hybrid : public ngraph::pass::FunctionPass
{
public:
    Hybrid(std::shared_ptr<runtime::Backend> fallback_backend);

    static void add_hybrid_to_pass_manager(ngraph::pass::Manager& manager);

private:
    virtual bool run_on_function(std::shared_ptr<ngraph::Function> function) override;
    void rewrite_function(const std::shared_ptr<Function>& f);

    std::vector<std::unordered_set<std::shared_ptr<Node>>>
        group_function_nodes_to_clusters(const std::shared_ptr<Function>& f);
    Node* take_independent_node_with_placement_priority(
        std::vector<std::deque<Node*>>& independent_nodes_by_placement, size_t placement);
    bool is_fallback(const Node* node) const;
    bool is_fallback(std::shared_ptr<Node> node) const;
    size_t get_placement(const Node* node) const;
    size_t get_placement(std::shared_ptr<Node> node) const;

    std::shared_ptr<runtime::Backend> m_fallback_backend;
};