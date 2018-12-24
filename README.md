# sudoku
sudoku文件夹是命令程序项目的源代码项目

sudokuGame文件夹是C#GUI程序的源代码项目

Bin文件夹和Resource文件夹只是最终版的文件

带commit注释信息的文件在sudoku文件夹中

数独终局游戏
sudoku 是集合数独生成器，数独解题器，以及数独问题生成器功能的项目，主要目的是为了
数独游戏提供数据生成和处理的工具
使用方法：
        1、命令行定位到当前sudoku.exe的文件夹
        2、运行./sudoku.exe -c number或者sudoku.exe -c number 
           其中number为正整数，将会生成number个不同的数独终局，并存放到同文件夹的sudoku.txt文件中
        3、运行./sudoku.exe -s absoluteFilePath 或者 sudoku.exe -s absoluteFilePath
           程序会从提供路径的文件中读取数独问题，并输出对应的解到sudoku.txt中
        4、运行./sudoku.exe -p number 或者 sudoku.exe -p number (number 为正整数)
           程序会从sudoku.txt中读取数独终局，根据一定规则通过随机挖空的方式产生数独问题并输出到ques.txt文件中保存

sudokuGame 是在sudoku.exe的基础上添加了一个简单的gui界面
使用方法：保证sudoku.exe 和sudokuGame.exe在同一个文件夹，
        1、双击sudokuGame.exe，游戏就会启动
        2、点击“开始游戏”，会自动生成一个待解的数独问题，
        3、在9*9的网格中，在空白的方格中填入适当的数字，
        4、确定完成后，点击提交，系统会提示你的答案正确与否
        6、若答题错误，可以继续修改原答案，反复提交；也可以点击“下一题”
        7、答题正确，点击“下一题”，将会生成新的数独问题，你可以继续进行数独解题的乐趣
        
