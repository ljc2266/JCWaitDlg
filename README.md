等待动画是友好的用户交互不可获取的功能，本文实现了基于MFC的等待动画。首先进行分析：

等待动画需要独立于业务
等待动画需要阻塞当前窗口
动画背景透明（非必须）
为了达到以上效果我们选用模式对话框+线程的方式来实现。

思路是：模式对话框显示动画效果，业务线程绑定到模态对话框上，线程结束时模态对话框随之结束。首先展示效果：
![Image text](https://raw.githubusercontent.com/ljc2266/JCWaitDlg/master/show.png)
使用JCThreadManager进行多线程管理，可以在作者这里找到开源代码。
