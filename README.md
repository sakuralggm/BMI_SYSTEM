#  BMI管理

##  安装

1. 在项目目录`BMI_SYSTEM`下打开终端
2. 执行`make`命令，编译项目
3. 执行`make install`命令，安装动态库
4. 执行`./main`命令，开始使用

##  测试建议

我们提供了一个有50条BMI记录的用户数据，可以更全面的测试系统的功能，使用方式如下：

1. 执行`./main`命令，看到登录界面

   ![image-20230703195048381](C:/Users/Jerry/AppData/Roaming/Typora/typora-user-images/image-20230703195048381.png)

2. 输入`1`，进入登录功能，用户名是`jj`，密码是`ljj`，回车

   ![image-20230703195136812](C:/Users/Jerry/AppData/Roaming/Typora/typora-user-images/image-20230703195136812.png)

3. 进入用户主界面，有三个功能可以测试

   ![image-20230703195225644](C:/Users/Jerry/AppData/Roaming/Typora/typora-user-images/image-20230703195225644.png)

4. 记录量大主要是测试查看历史BMI功能，所以我们输入`2`，回车，进入该功能，看到如下界面

   ![image-20230703195326057](C:/Users/Jerry/AppData/Roaming/Typora/typora-user-images/image-20230703195326057.png)

5. 测试功能

   * n下一页

     ![image-20230703195514471](C:/Users/Jerry/AppData/Roaming/Typora/typora-user-images/image-20230703195514471.png)

     ![image-20230703195403687](C:/Users/Jerry/AppData/Roaming/Typora/typora-user-images/image-20230703195403687.png)

   * p上一页

     ![image-20230703195442252](C:/Users/Jerry/AppData/Roaming/Typora/typora-user-images/image-20230703195442252.png)

     ![image-20230703195454392](C:/Users/Jerry/AppData/Roaming/Typora/typora-user-images/image-20230703195454392.png)

   * s排序

     ![image-20230703195554720](C:/Users/Jerry/AppData/Roaming/Typora/typora-user-images/image-20230703195554720.png)

   * t设置时间格式

     ![image-20230703195621344](C:/Users/Jerry/AppData/Roaming/Typora/typora-user-images/image-20230703195621344.png)

   * g查看柱状图

     ![image-20230703195643522](C:/Users/Jerry/AppData/Roaming/Typora/typora-user-images/image-20230703195643522.png)

##  退出

如果在查看历史BMI页面，请按照以下步骤安全退出

1. 输入`q`，回车

   ![image-20230703195829216](C:/Users/Jerry/AppData/Roaming/Typora/typora-user-images/image-20230703195829216.png)

2. 输入`3`，回车

   ![image-20230703195859627](C:/Users/Jerry/AppData/Roaming/Typora/typora-user-images/image-20230703195859627.png)

3. 输入`0`，回车

   ![image-20230703195922175](C:/Users/Jerry/AppData/Roaming/Typora/typora-user-images/image-20230703195922175.png)


