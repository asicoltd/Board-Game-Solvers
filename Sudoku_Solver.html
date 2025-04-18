
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>Sudoku Solver with Validation</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      text-align: center;
    }
    table {
      border-collapse: collapse;
      margin: 20px auto;
    }
    td {
      border: 1px solid #999;
      width: 40px;
      height: 40px;
      position: relative;
    }
    input {
      width: 38px;
      height: 38px;
      text-align: center;
      font-size: 18px;
      border: none;
    }
    .thick-border {
      border-width: 2px;
    }
    .error {
      background-color: #f88 !important;
    }
    button {
      padding: 10px 20px;
      font-size: 16px;
      margin: 10px;
    }
    textarea {
      width: 360px;
      height: 120px;
      font-size: 16px;
      margin-top: 10px;
    }
    #numpad {
      display: none;
      position: absolute;
      z-index: 999;
      background: #fff;
      border: 1px solid #000;
      padding: 5px;
      border-radius: 8px;
    }
    #numpad button {
      width: 36px;
      height: 36px;
      font-size: 16px;
      margin: 2px;
    }
  </style>
</head>
<body>
  <h1>Sudoku Solver with Validation</h1>
  <table id="sudokuGrid"></table>
  <button onclick="solve()">Solve</button>
  <button onclick="resetGrid()">Reset</button>
  <button onclick="validateGrid()">Validate</button>
  <br>
  <textarea id="sudokuInput" placeholder="Paste Sudoku here: 0 0 1 ... or 0,0,1,..."></textarea><br>
  <button onclick="loadInput()">Load Input</button>

  <div id="numpad"></div>

  <script>
    const grid = document.getElementById("sudokuGrid");
    let selectedInput = null;

    function createGrid() {
      for (let i = 0; i < 9; i++) {
        const row = document.createElement("tr");
        for (let j = 0; j < 9; j++) {
          const cell = document.createElement("td");
          if (i % 3 === 0) cell.classList.add("thick-border");
          if (j % 3 === 0) cell.classList.add("thick-border");
          const input = document.createElement("input");
          input.type = "text";
          input.maxLength = 1;
          input.value = "0";
          input.readOnly = true;
          input.addEventListener("focus", (e) => showNumpad(e.target));
          cell.appendChild(input);
          row.appendChild(cell);
        }
        grid.appendChild(row);
      }
    }

    function showNumpad(input) {
  selectedInput = input;
  const numpad = document.getElementById("numpad");
  numpad.innerHTML = "";

  const td = input.parentElement;
  const rowIdx = td.parentElement.rowIndex;
  const colIdx = td.cellIndex;
  const sud = getGrid();

  const isValid = (num) => {
    sud[rowIdx][colIdx] = num;
    const ok = check(sud, rowIdx, colIdx, num);
    sud[rowIdx][colIdx] = 0;
    return ok;
  };

  for (let i = 1; i <= 9; i++) {
    const btn = document.createElement("button");
    btn.textContent = i;
    if (isValid(i)) {
      btn.style.backgroundColor = "#aaffaa"; // green
    } else {
      btn.style.backgroundColor = "#ffdddd"; // light red
    }
    btn.onclick = () => {
      selectedInput.value = i;
      numpad.style.display = "none";
    };
    numpad.appendChild(btn);
  }

  const clearBtn = document.createElement("button");
  clearBtn.textContent = "0";
  clearBtn.onclick = () => {
    selectedInput.value = 0;
    numpad.style.display = "none";
  };
  numpad.appendChild(clearBtn);

  const rect = input.getBoundingClientRect();
  numpad.style.left = `${rect.left + window.scrollX}px`;
  numpad.style.top = `${rect.bottom + window.scrollY}px`;
  numpad.style.display = "block";
}


    document.addEventListener("click", function (e) {
      const numpad = document.getElementById("numpad");
      if (!numpad.contains(e.target) && e.target.tagName !== "INPUT") {
        numpad.style.display = "none";
      }
    });

    function getGrid() {
      const sud = [];
      for (let i = 0; i < 9; i++) {
        const row = [];
        for (let j = 0; j < 9; j++) {
          const input = grid.rows[i].cells[j].children[0];
          const val = parseInt(input.value) || 0;
          input.classList.remove("error");
          row.push(val);
        }
        sud.push(row);
      }
      return sud;
    }

    function setGrid(sud) {
      for (let i = 0; i < 9; i++) {
        for (let j = 0; j < 9; j++) {
          grid.rows[i].cells[j].children[0].value = sud[i][j];
        }
      }
    }

    function check(sud, row, col, num) {
      for (let i = 0; i < 9; i++) {
        if (sud[row][i] === num && i !== col) return false;
        if (sud[i][col] === num && i !== row) return false;
      }
      const startRow = row - row % 3, startCol = col - col % 3;
      for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
          const r = startRow + i, c = startCol + j;
          if ((r !== row || c !== col) && sud[r][c] === num) return false;
        }
      }
      return true;
    }

    function solveSudoku(sud) {
      for (let row = 0; row < 9; row++) {
        for (let col = 0; col < 9; col++) {
          if (sud[row][col] === 0) {
            for (let num = 1; num <= 9; num++) {
              if (check(sud, row, col, num)) {
                sud[row][col] = num;
                if (solveSudoku(sud)) return true;
                sud[row][col] = 0;
              }
            }
            return false;
          }
        }
      }
      return true;
    }

    function solve() {
      const sud = getGrid();
      if (validateGrid()) {
        if (solveSudoku(sud)) {
          setGrid(sud);
          alert("Sudoku Solved!");
        } else {
          alert("No solution exists!");
        }
      } else {
        alert("Fix the errors before solving.");
      }
    }

    function resetGrid() {
      for (let i = 0; i < 9; i++) {
        for (let j = 0; j < 9; j++) {
          grid.rows[i].cells[j].children[0].value = 0;
          grid.rows[i].cells[j].children[0].classList.remove("error");
        }
      }
    }

    function loadInput() {
      const input = document.getElementById("sudokuInput").value;
      const nums = input
        .replace(/\n/g, " ")
        .replace(/,/g, " ")
        .split(/\s+/)
        .filter(x => x.length)
        .map(Number);
      if (nums.length !== 81) {
        alert("Invalid input. Must contain 81 numbers.");
        return;
      }
      let idx = 0;
      for (let i = 0; i < 9; i++) {
        for (let j = 0; j < 9; j++) {
          const cell = grid.rows[i].cells[j].children[0];
          cell.value = nums[idx++];
          cell.classList.remove("error");
        }
      }
    }

    function validateGrid() {
      const sud = getGrid();
      let valid = true;

      for (let i = 0; i < 9; i++) {
        for (let j = 0; j < 9; j++) {
          const val = sud[i][j];
          if (val !== 0 && !check(sud, i, j, val)) {
            grid.rows[i].cells[j].children[0].classList.add("error");
            valid = false;
          }
        }
      }
      return valid;
    }

    createGrid();
  </script>
</body>
</html>
