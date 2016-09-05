using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GameOfLifePort
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
                    cout << "Enter two values for grid size. Recommended: 5 x 5" << endl;
            
                    cout << "Y: ";
                    string y_preconversion;
                    cin >> y_preconversion;
                    cout << endl;
                    y = stoi(y_preconversion);

                    cout << "X: ";
                    string x_preconversion;
                    cin >> x_preconversion;
                    cout << endl;
                    x = stoi(x_preconversion);

                    break;
                }
                catch (out_of_range)
                {
                    cerr << "Out of Range Error. Please input valid numbers" << endl;
                }
                catch (invalid_argument)
                {
                    cerr << "Invalid Argument. Please input valid numbers" << endl;
                }
            }

            for (;;)
            {
                try
                {
                    cout << "Enter number of loops (0 to run until no changes in generation): ";
                    string num_of_loops_preconversion;
                    cin >> num_of_loops_preconversion;
                    cout << endl;
                    num_of_loops = stoi(num_of_loops_preconversion);

                    break;
                }
                catch (out_of_range)
                {
                    cerr << "Out of Range Error. Please input valid numbers" << endl;
                }
                catch (invalid_argument)
                {
                    cerr << "Invalid Argument. Please input valid numbers" << endl;
                }
            }

            for (;;)
            {
                try
                {
                    cout << "Use default inital locations?" << endl;
                    cout << "Y: 1, X: 1" << endl;
                    cout << "Y: 2, X: 1" << endl;
                    cout << "Y: 2, X: 2" << endl;
                    cout << "Note: Only one (1) generation possible" << endl;
                    cout << "Use defaults? (Y/N): ";
                    string default_inital_values;
                    cin >> default_inital_values;
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
                        throw invalid_argument("Input not Y or N");
                    }

                    break;
                }
                catch (invalid_argument)
                {
                    cerr << "Invalid Argument. Please enter valid input" << endl;
                }
            }
            Grid GameGrid(y, x);
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

            Life Main(GameGrid.return_grid(), y, x);
            Main.Start(num_of_loops);

            char pause;
            cin >> pause;

	        return 0;
        }
    }
}