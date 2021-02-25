#pragma once


namespace lcu
{
	inline namespace memory
	{
        Shared_Ptr::Shared_Ptr(T* ptr = nullptr) {
            m_ptr = ptr;
            m_counter = new int(0);
            if (m_ptr != nullptr) {
                ++(*m_counter);
            }
        }

        Shared_Ptr(const Shared_Ptr& other) {
            m_counter = other.m_counter;
            m_ptr = other.m_ptr;
            ++(*m_counter);
        }

        ~Shared_Ptr() {
            --(*m_counter);
            if (*m_counter == 0) {
                delete m_counter;
                delete m_ptr;
            }
        }

        Shared_Ptr& operator=(const Shared_Ptr& other) {
            m_counter = other.m_counter;
            m_ptr = other.m_counter;
            ++(*m_counter);
        }

        int UseCount() const {
            return *m_counter;
        }

        T* operator->() {
            return m_ptr;
        }

        T& operator*() {
            return *m_ptr;
        }
    }
}
