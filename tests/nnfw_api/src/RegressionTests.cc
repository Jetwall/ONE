/*
 * Copyright (c) 2020 Samsung Electronics Co., Ltd. All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "fixtures.h"
#include "NNPackages.h"

TEST_F(RegressionTest, github_1535)
{
  auto package_path = NNPackages::get().getModelAbsolutePath(NNPackages::ADD);

  nnfw_session *session1 = nullptr;
  NNFW_ENSURE_SUCCESS(nnfw_create_session(&session1));
  NNFW_ENSURE_SUCCESS(nnfw_load_model_from_file(session1, package_path.c_str()));
  NNFW_ENSURE_SUCCESS(nnfw_set_available_backends(session1, "cpu;acl_cl;acl_neon"));
  NNFW_ENSURE_SUCCESS(nnfw_prepare(session1));

  nnfw_session *session2 = nullptr;
  NNFW_ENSURE_SUCCESS(nnfw_create_session(&session2));
  NNFW_ENSURE_SUCCESS(nnfw_load_model_from_file(session2, package_path.c_str()));
  NNFW_ENSURE_SUCCESS(nnfw_set_available_backends(session2, "cpu"));
  NNFW_ENSURE_SUCCESS(nnfw_prepare(session2));

  NNFW_ENSURE_SUCCESS(nnfw_close_session(session1));
  NNFW_ENSURE_SUCCESS(nnfw_close_session(session2));
}
