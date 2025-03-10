What is a 𝗠𝗮𝗴𝗶𝗰 𝗦𝗾𝘂𝗮𝗿𝗲?

A magic square is an N × N grid where the numbers from 1 to N² are arranged so that each row, column, and diagonals sum up to the same value. The algorithm follows a simple yet fascinating mechanism:

1️⃣ Start with 1 in the middle of the first row.

2️⃣ The next number moves diagonally up and right.

3️⃣ If the position goes out of bounds, it wraps around (top moves to bottom, right moves to left).

4️⃣ If the cell is occupied, move directly down instead.

5️⃣ Repeat until the grid is filled.
