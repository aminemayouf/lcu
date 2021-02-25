#pragma once

namespace lcu
{
	inline namespace memory
	{
        template <typename T>
        class Unique_Ptr {

            public:
            Unique_Ptr(T* ptr = nullptr) : m_ptr(ptr) {}
            Unique_Ptr(const Unique_Ptr&) = delete;
            Unique_Ptr(Unique_Ptr&& other) {
                m_ptr = other.m_ptr;
                other.m_ptr = nullptr;
            }
            
            ~Unique_Ptr() {
                delete m_ptr;
            }
            
            Unique_Ptr& operator=(const Unique_Ptr&) = delete;
            Unique_Ptr& operator=(Unique_Ptr&& other) {
                m_ptr = other.m_ptr;
                other.m_ptr = nullptr;
                return *this;
            }

            T* operator->() {
                return m_ptr;
            }

            T& operator*() {
                return *m_ptr;
            }

            private:
            T* m_ptr;
        };
    }
}
