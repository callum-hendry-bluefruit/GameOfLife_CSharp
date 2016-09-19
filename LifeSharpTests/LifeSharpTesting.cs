using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace LifeSharpTests
{
    [TestClass]
    public class LifeSharpTesting
    {
        [TestMethod]
        public void allocate_array_in_correct_size_and_initalise()
        {
            int x = 5, y = 5;
            GameOfLifeSharp.Grid GameGrid = new GameOfLifeSharp.Grid(y, x);

            char expected = '.';

            for (int i = 0; i < y; i++)
            {
                for (int j = 0; j < x; j++)
                {
                    Assert.AreEqual(expected, GameGrid.GetGridValue(i, j));
                }
            }
        }

        [TestMethod]
        public void end_result()
        {
            int x = 5, y = 5;

            GameOfLifeSharp.Grid GameGrid = new GameOfLifeSharp.Grid(y, x);
            GameGrid.ToggleCell(1, 1);
            GameGrid.ToggleCell(1, 2);
            GameGrid.ToggleCell(2, 1);

            GameOfLifeSharp.Life EndResultTest = new GameOfLifeSharp.Life(GameGrid.ReturnGrid(), y, x);

            EndResultTest.Start(1);

            char expected_alive = '*';
            Assert.AreEqual(expected_alive, EndResultTest.GetGridValue(1, 1));
            Assert.AreEqual(expected_alive, EndResultTest.GetGridValue(1, 2));
            Assert.AreEqual(expected_alive, EndResultTest.GetGridValue(2, 1));
            Assert.AreEqual(expected_alive, EndResultTest.GetGridValue(2, 2));
        }

        [TestMethod]
        public void end_result_2()
        {
            int x = 5, y = 5;
            GameOfLifeSharp.Grid GameGrid = new GameOfLifeSharp.Grid(y, x);
    
            GameGrid.ToggleCell(4, 3);
            GameGrid.ToggleCell(4, 4);
            GameGrid.ToggleCell(3, 4);

            GameOfLifeSharp.Life EndResultTest = new GameOfLifeSharp.Life(GameGrid.ReturnGrid(), y, x);
            EndResultTest.Start(1);

            char expected_alive = '*';
            Assert.AreEqual(expected_alive, EndResultTest.GetGridValue(4, 3));
            Assert.AreEqual(expected_alive, EndResultTest.GetGridValue(4, 4));
            Assert.AreEqual(expected_alive, EndResultTest.GetGridValue(3, 4));
            Assert.AreEqual(expected_alive, EndResultTest.GetGridValue(3, 3));
        }

        [TestMethod]
        public void larger_grid()
        {
            int x = 10, y = 10;
            GameOfLifeSharp.Grid GameGrid = new GameOfLifeSharp.Grid(y, x);

            GameGrid.ToggleCell(4, 3);
            GameGrid.ToggleCell(4, 4);
            GameGrid.ToggleCell(3, 4);

            GameOfLifeSharp.Life EndResultTestWithLargerGrid = new GameOfLifeSharp.Life(GameGrid.ReturnGrid(), y, x);
            EndResultTestWithLargerGrid.Start(1);

            char expected_alive = '*';
            Assert.AreEqual(expected_alive, EndResultTestWithLargerGrid.GetGridValue(4, 3));
            Assert.AreEqual(expected_alive, EndResultTestWithLargerGrid.GetGridValue(4, 4));
            Assert.AreEqual(expected_alive, EndResultTestWithLargerGrid.GetGridValue(3, 4));
            Assert.AreEqual(expected_alive, EndResultTestWithLargerGrid.GetGridValue(3, 3));
        }

        [TestMethod]
        public void larger_grid_edges()
        {
            int x = 10, y = 10;
            GameOfLifeSharp.Grid GameGrid = new GameOfLifeSharp.Grid(y, x);

            GameGrid.ToggleCell(9, 3);
            GameGrid.ToggleCell(9, 4);
            GameGrid.ToggleCell(8, 4);
            GameGrid.ToggleCell(8, 5);
            GameGrid.ToggleCell(5, 2);
            GameGrid.ToggleCell(4, 3);
            GameGrid.ToggleCell(3, 4);

            GameOfLifeSharp.Life EndResultTestWithLargerGrid = new GameOfLifeSharp.Life(GameGrid.ReturnGrid(), y, x);
            char expected_alive = '*';

            EndResultTestWithLargerGrid.Start(1);

            Assert.AreEqual(expected_alive, EndResultTestWithLargerGrid.GetGridValue(4, 3)); //Fail 
            Assert.AreEqual(expected_alive, EndResultTestWithLargerGrid.GetGridValue(8, 3));
            Assert.AreEqual(expected_alive, EndResultTestWithLargerGrid.GetGridValue(8, 4)); //Fail
            Assert.AreEqual(expected_alive, EndResultTestWithLargerGrid.GetGridValue(8, 5)); //Fail
            Assert.AreEqual(expected_alive, EndResultTestWithLargerGrid.GetGridValue(9, 3));
            Assert.AreEqual(expected_alive, EndResultTestWithLargerGrid.GetGridValue(9, 4));
            Assert.AreEqual(expected_alive, EndResultTestWithLargerGrid.GetGridValue(9, 5)); //Fail
        }

        [TestMethod]
        public void small_grid()
        {
            int x = 1, y = 1;
            GameOfLifeSharp.Grid GameGrid = new GameOfLifeSharp.Grid(y, x);

            GameGrid.ToggleCell(0, 0);
            GameOfLifeSharp.Life EndResultTestWith1x1Grid = new GameOfLifeSharp.Life(GameGrid.ReturnGrid(), y, x);

            EndResultTestWith1x1Grid.Start(1);

            char expected_dead = '.';
            Assert.AreEqual(expected_dead, EndResultTestWith1x1Grid.GetGridValue(0, 0));
        }

        [TestMethod]
        public void rectangular_grid()
        {
            int x = 8, y = 4;
            GameOfLifeSharp.Grid GameGrid = new GameOfLifeSharp.Grid(y, x);
    
            GameGrid.ToggleCell(0, 0);
            GameGrid.ToggleCell(0, 1);
            GameGrid.ToggleCell(1, 0);

            GameGrid.ToggleCell(3, 6);
            GameGrid.ToggleCell(3, 7);
            GameGrid.ToggleCell(2, 7);

            GameOfLifeSharp.Life EndResultTestWithRectangularGrid = new GameOfLifeSharp.Life(GameGrid.ReturnGrid(), y, x);
            EndResultTestWithRectangularGrid.Start(1);

            char expected_alive = '*';
            Assert.AreEqual(expected_alive, EndResultTestWithRectangularGrid.GetGridValue(0, 0));
            Assert.AreEqual(expected_alive, EndResultTestWithRectangularGrid.GetGridValue(0, 1));
            Assert.AreEqual(expected_alive, EndResultTestWithRectangularGrid.GetGridValue(1, 0));
            Assert.AreEqual(expected_alive, EndResultTestWithRectangularGrid.GetGridValue(1, 1));

            Assert.AreEqual(expected_alive, EndResultTestWithRectangularGrid.GetGridValue(3, 6));
            Assert.AreEqual(expected_alive, EndResultTestWithRectangularGrid.GetGridValue(3, 7));
            Assert.AreEqual(expected_alive, EndResultTestWithRectangularGrid.GetGridValue(2, 7));
            Assert.AreEqual(expected_alive, EndResultTestWithRectangularGrid.GetGridValue(2, 6));
        }
    }
}