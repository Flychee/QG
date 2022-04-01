import numpy as np
from sklearn.datasets import load_boston
import pandas as pd
import matplotlib.pyplot as plt #可视化
import os
class Boston :
    boston = load_boston()#导入数据集
    x = boston['data']  # 特征变量
    y = boston['target']  # 目标变量
    def Check(self,boston):
        if pd.isnull(boston):
            print("数据缺失")
        else:
            print("数据完整")
    def L_S_Method(self,x,y):#最小二乘法
        x_m = np.array(x,dtype = float)#转为矩阵
        temp = np.ones(506)
        x_m = np.insert(x_m,13,temp,axis = 1)#在最后插入一列1矩阵求w0
        y_m = np.array(y,dtype = float)
        x_all = x_m.T.dot(x_m)
        x_all = np.linalg.inv(x_all)
        xy = np.dot(x_m.T,y_m)
        w = x_all.dot(xy)
        print(w)
        exit()

        longstring ="""注分别为城镇人口犯罪率
超过25000平方英尺的住宅用地所占比例
城镇非零售业务地区的比例
查尔斯河虚拟变量(如果土地在河边=1；否则是0)
一氧化氮浓度(每1000万份)
平均每居民房数
在1940年之前建成的所有者占用单位的比例
与五个波士顿就业中心的加权距离
辐射状公路的可达性指数
每10,000美元的全额物业税率
城镇师生比例
人口中地位较低人群的百分数
以1000美元计算的自有住房的中位数"""
        print(longstring)
        print("请输入上述13个值(中间用逗号隔开)：")
        ip = input()
        ip = ip.split(",")
        if len(ip)>13:
            for i2 in range(len(ip)-13):
                ip.pop()#删除多余数据
        if len(ip)<13:
            for i3 in range(13-len(ip)):
                ip.append(0)#补齐数据
        for i4 in range(len(ip)):
            try:
                ip[i4] = float(ip[i4])
            except:
                ip[i4] = 0.0
        print("数据整理为")
        print(ip)
        ip.append(1.0)#与w0相乘
        ip = np.array(ip)
        Result = np.dot(ip,w)
        print("预测房价为(单位：1000美元)")
        print(Result)

    def Visual(self,x,y ,boston):#散点图可视化
        name = boston['feature_names'] #变量名
        for i in range(13):
            plt.figure()
            plt.grid()#网格线设置
            plt.xlabel(name[i])
            plt.ylabel('Housing Price')
            plt.title(name[i]+'-Housing Price')#表格名
            plt.scatter(x[:,i] , y ,s=5)#基本数据
        plt.show()
bst = Boston()
while 1:
    i = os.system("cls")#清屏
    print("1.检查数据是否完整")
    print("2.预测房价")
    print("3.变量可视化")
    print("4.退出程序")
    num = input("请输入序号：")
    if num == '1':
        bst.Check(bst.boston)
    elif num == '2':
        bst.L_S_Method(bst.x,bst,y)
    elif num == '3':
        bst.Visual(bst.x,bst.y,bst.boston)
    elif num == '4':
        exit()
    input("按任意键继续")




