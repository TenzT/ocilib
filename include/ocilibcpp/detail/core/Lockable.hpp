/*
 * OCILIB - C Driver for Oracle (C Wrapper for Oracle OCI)
 *
 * Website: http://www.ocilib.net
 *
 * Copyright (c) 2007-2020 Vincent ROGIER <vince.rogier@ocilib.net>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "ocilibcpp/core.hpp"

// ReSharper disable CppClangTidyHicppUseEqualsDefault
// ReSharper disable CppClangTidyModernizeUseEqualsDefault
// ReSharper disable CppClangTidyHicppUseAuto
// ReSharper disable CppClangTidyModernizeUseAuto

namespace ocilib
{
    namespace core
    {
        inline Lockable::Lockable() : _locker(nullptr)
        {

        }

        inline Lockable::~Lockable() noexcept
        {

        }

        inline void Lockable::Lock() const
        {
            if (_locker)
            {
                _locker->Lock();
            }
        }

        inline void Lockable::Unlock() const
        {
            if (_locker)
            {
                _locker->Unlock();
            }
        }

        inline void Lockable::SetLocker(Locker* locker)
        {
            _locker = locker;
        }

    }
}