**Finding the Time Period with the Most Visitors**

**Problem Statement**

Given a list of entering and leaving times of visitors at a museum, we want to find the time period when there were the most visitors and determine the number of visitors during that time.

**Approach**

1. **Data Input and Preprocessing**:
   1. Read the visiting times from the input file.
   1. Convert the time values to minutes (e.g., 10:15 becomes 615 minutes).
   1. Maintain an unordered map (hash map) to track the visitor count for each minute.
1. **Increment Visitor Count**:
   1. For each visitor, iterate over the time range (from entering time to leaving time).
   1. Increment the visitor count for each minute within the range.
   1. Keep track of the maximum visitor count encountered.
1. **Find the Time Period**:
   1. After processing all visitors, identify the time period with the maximum visitor count.
   1. Start from the minute with the maximum visitor count and find the end time of this period (i.e., the last minute with the same maximum count).
1. **Convert Minutes Back to HH:MM Format**:
   1. Convert the start and end minutes back to HH:MM format.
   1. Output the result in the form <start time>-<end time>;<number of visitors>.

**Example**

Suppose we have the following visitor times:

- 10:15,14:20
- 11:10,15:22
1. Convert to minutes:
   1. Visitor 1: 10:15-14:20 → 615-860
   1. Visitor 2: 11:10-15:22 → 670-922
1. Update visitor counts:
   1. For each minute from 615 to 860, increment the count.
   1. For each minute from 670 to 922, increment the count.
1. Maximum visitor count: 2 (from 11:10 to 14:20).
   1. Start time: 11:10
   1. End time: 14:20
1. Output: 11:10-14:20;2

**Conclusion**

The algorithm efficiently processes the visitor times and identifies the time period with the most visitors. It ensures accurate results even when the input times are not sorted or in random order.

