let rows = 20;
let cols = 20;
let grid;
let nextGenerationMatrix;
let delay = 1000;

function setup() {
    createCanvas(windowWidth, windowHeight);
    calculateGridSize();
    grid = createMatrix(rows, cols);
    nextGenerationMatrix = createMatrix(rows, cols);
    fillRandom(grid);
    frameRate(1 / (delay / 1000));
}

function draw() {
    background(255);
    let cellSize = min(width / cols, height / rows);
    for (let row = 0; row < rows; row++) {
        for (let col = 0; col < cols; col++) {
            let x = col * cellSize;
            let y = row * cellSize;
            if (grid[row][col] === 1) {
                fill(0);
            } else {
                fill(255);
            }
            rect(x, y, cellSize, cellSize);
        }
    }
    nextGeneration();
}

function calculateGridSize() {
    let cellSize = min(width / cols, height / rows);
    cols = floor(width / cellSize);
    rows = floor(height / cellSize);
}

function createMatrix(rows, cols) {
    let array = new Array(rows);
    for (let row = 0; row < array.length; row++) {
        array[row] = new Array(cols).fill(0);
    }
    return array;
}

function fillRandom(array) {
    for (let row = 0; row < rows; row++) {
        for (let col = 0; col < cols; col++) {
            array[row][col] = Math.round(Math.random());
        }
    }
}

function countNeighbors(matrix, row, col) {
    let totBacterias = 0;
    for (let i = -1; i <= 1; i++) {
        for (let j = -1; j <= 1; j++) {
            let neighborRow = row + i;
            let neighborCol = col + j;
            if (neighborRow >= 0 && neighborRow < rows && neighborCol >= 0 && neighborCol < cols && !(i === 0 && j === 0)) {
                totBacterias += matrix[neighborRow][neighborCol];
            }
        }
    }
    return totBacterias;
}

function nextGeneration() {
    for (let row = 0; row < rows; row++) {
        for (let col = 0; col < cols; col++) {
            let totBacterias = countNeighbors(grid, row, col);
            if (grid[row][col] === 1) {
                if (totBacterias < 2 || totBacterias > 3) {
                    nextGenerationMatrix[row][col] = 0;
                } else {
                    nextGenerationMatrix[row][col] = 1;
                }
            } else {
                if (totBacterias === 3) {
                    nextGenerationMatrix[row][col] = 1;
                } else {
                    nextGenerationMatrix[row][col] = 0;
                }
            }
        }
    }
    let temp = grid;
    grid = nextGenerationMatrix;
    nextGenerationMatrix = temp;
}