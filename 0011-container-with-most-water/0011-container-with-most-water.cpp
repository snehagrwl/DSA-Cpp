class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0; // start pointer
        int right = height.size() - 1; // end pointer
        int max_area = 0; // to keep track of max area found

        while (left < right) {
            // Calculate the height as the smaller of two lines
            int h = min(height[left], height[right]);
            // Calculate width between the two pointers
            int w = right - left;
            // Calculate current area
            int current_area = h * w;
            // Update max_area if current is bigger
            max_area = max(max_area, current_area);

            // Move the pointer with smaller height inward
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max_area;
    }
};
