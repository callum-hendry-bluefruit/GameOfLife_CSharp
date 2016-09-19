using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GameOfLifeSharp
{
    static class LifeSharpMain
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new LifeSharpDisplay());

            int y, x, num_of_loops;
            bool default_values = false;
            for (;;)
            {
                try
                {
                    Console.WriteLine("Enter two values for grid size. Recommended: 5 x 5");
            
                    Console.Write("Y: ");
                    y = Convert.ToInt32(Console.ReadLine());
                    Console.WriteLine();

                    Console.Write("X: ");
                    x = Convert.ToInt32(Console.ReadLine());
                    Console.WriteLine();

                    break;
                }
                catch (OverflowException)
                {
                    Console.WriteLine("Out of Range Error. Please enter number equal to or less than: ");
                }
                catch (FormatException)
                {
                    Console.WriteLine("Invalid character was entered");
                }
            }

            for (;;)
            {
                try
                {
                    Console.Write("Enter number of loops (0 to run until no changes in generation): ");
                    num_of_loops = Convert.ToInt32(Console.ReadLine());
                    Console.WriteLine();

                    break;
                }
                catch (OverflowException)
                {
                    Console.WriteLine("Out of Range Error. Please enter number equal to or less than: ");
                }
                catch (FormatException)
                {
                    Console.WriteLine("Invalid character was entered");
                }
            }

            for (;;)
            {
                try
                {
                    Console.WriteLine("Use default inital locations?");
                    Console.WriteLine("Y: 1, X: 1");
                    Console.WriteLine("Y: 2, X: 1");
                    Console.WriteLine("Y: 2, X: 2");
                    Console.Write("Note: Only one (1) generation possible");
                    Console.Write("Use defaults? (Y/N): ");
                    string default_inital_values = Console.ReadLine();
                    if (default_inital_values == "Y" || default_inital_values == "y")
                    {
                        default_values = true;
                    }
                    else if (default_inital_values == "N" || default_inital_values == "n")
                    {
                        default_values = false;
                    }
                    else
                    {
                        throw new FormatException("Input not Y or N");
                    }

                    break;
                }
                catch (FormatException)
                {
                    Console.WriteLine("Invalid character was entered");
                }
            }
            Grid GameGrid = new Grid(y, x);
            if (default_values == false)
            {
                GameGrid.UserChosenStartLocations();
            }
            else
            {
                GameGrid.ToggleCell(1, 1);
                GameGrid.ToggleCell(2, 1);
                GameGrid.ToggleCell(2, 2);
            }

            Life Main = new Life(GameGrid.ReturnGrid(), y, x);
            Main.Start(num_of_loops);

            string pause = Console.ReadLine();
        }
    }
}