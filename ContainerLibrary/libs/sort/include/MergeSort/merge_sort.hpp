#pragma once

namespace ms {
	template <typename T, typename A>
	void merge(A*, T, T, T, bool);

	template <typename T, typename A>
	void merge_sort(A *a, T low, T high, bool sort_ascending = true) {
		int mid;

		// Recursively call merge_sort to split the array down to single elements
		if (low < high) {
			mid = (low + high) / 2;
			merge_sort(a, low, mid, sort_ascending);
			merge_sort(a, mid + 1, high, sort_ascending);
			merge(a, low, high, mid, sort_ascending);
		}
		return;
	}

	template <typename T, typename A>
	void merge(A *a, T low, T high, T mid, bool sort_ascending) {
		A c[500]; // Allocate a 'maximum' size to be able to sort

		T low_index, high_index, current_index;
		low_index = current_index = low;
		high_index = mid + 1;


		while (low_index <= mid || high_index <= high) {
			if (sort_ascending) {							/// Sort from low to high
				
				if (low_index > mid)						// lower half exhausted, copy from upper half
					c[current_index] = a[high_index++];

				else if (high_index > high)					// upper half exhausted, copy from lower half
					c[current_index] = a[low_index++];

				else if (a[low_index] < a[high_index])		// compare and copy if less than
					c[current_index] = a[low_index++];

				else										// lower is greater than upper, copy from upper
					c[current_index] = a[high_index++]; 

			} else {										/// Sort from high to low
				
				if (low_index > mid)						// lower half exhausted, copy from upper half
					c[current_index] = a[high_index++];

				else if (high_index > high)					// upper half exhausted, copy from lower half
					c[current_index] = a[low_index++];

				else if (a[low_index] > a[high_index])		// compare and copy if greater than
					c[current_index] = a[low_index++];

				else										// lower is less than upper, copy from upper
					c[current_index] = a[high_index++];
			}

			current_index++;
		}
		

		// Replace the values in the original array in their sorted positions
		for (low_index = low; low_index < current_index; low_index++) {
			a[low_index] = c[low_index];
		}
	}
}