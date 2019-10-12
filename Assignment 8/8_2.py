#ALBRIT BENDO
#PROBLEM 8.2
#RED BLACK TREE 

import sys
import os

Color = ("RED", "BLACK")  # red will be defined as 0 and black as 1


class Node:
    data = None
    parent = None
    color = None
    left = None
    right = None

    # first initialize all the values in the class node
    # the initialized color is black
    def __init__(self, data, parent=None, color=1, left=None, right=None):
        self.data = data
        self.parent = parent
        self.color = color
        self.left = left
        self.right = right

    def preorder(self, x):
        print(x.__r.data)
        self.preorder(self.left)
        self.preorder(self.right)


class RedBlackTree:
    # before starting...sentinel
    # will be used to replace the NULL of the pseudocode presented in class
    sentinel = Node(data=None, color=1)

    __r = None  # the root

    def __init__(self, __r = None):
        self.__r = Node(data=None, parent=None, color=1, left=self.sentinel, right=self.sentinel)

    # rotateLeft and rotateRight functions to fix the tree after each insertion
    def rotateLeft(self, x):
        y = x.right
        x.right = y.left
        if (y.left is not self.sentinel):
            y.left.parent = x
        y.parent = x.parent
        if (x.parent is self.sentinel):
            self.__r = y
        elif (x == x.parent.left):
            x.parent.left = y
        else:
            x.parent.right = y
        y.left = x
        x.parent = y

    def rotateRight(self, x):
        x = y.left
        y.left = x.right
        if (x.right is not self.sentinel):
            x.right.parent = y
        x.parent = y.parent
        if (y.parent is self.sentinel):
            self.__r = x
        elif (y == y.parent.right):
            y.parent.right = x
        else:
            y.parent.left = x
        x.right = y
        y.parent = x

    def insert(self, a):
        z = Node(a, 0)
        y = self.sentinel
        x = self.__r
        while (x.data != None):
            y = x
            if (z.data < x.data):
                x = x.left
            else:
                x = x.right
        z.parent = y
        if (y.data == None):
            self.__r = z
        elif (z.data < y.data):
            y.left = z
        else:
            y.right = z
        z.left = self.sentinel
        z.right = self.sentinel
        z.color = self.sentinel
        self.RBinsertfixup(z)

    def RBinsertfixup(self, z):  # the helper function used in the pseudocode
        while (z.parent.color == 0):
            if (z.parent == z.parent.parent.left):
                y = z.parent.parent.right
                if (y.color == 0):
                    z.parent.color = 1
                    y.color = 1
                    z.parent.parent.color = 0
                    z = z.parent.parent
                elif (z == z.parent.right):
                    z = z.parent
                    rotateLeft(self, z)
                z.parent.color = 1
                z.parent.parent.color = 0
                rotateRight(self, z.parent.parent)
            else:
                if (z.parent == z.parent.parent.right):
                    y = z.parent.parent.left
                    if (y.color == 0):
                        z.parent.color = 1
                        y.color = 1
                        z.parent.parent.color = 0
                        z = z.parent.parent
                    elif (z == z.parent.left):
                        z = z.parent
                        rotateRight(self, z)
                    z.parent.color = 1
                    z.parent.parent.color = 0
                    rotateLeft(self, z.parent.parent)
            self.__r.color = 1

    def TreeMinimum(x):
        a = x
        while (a.left.data is not None):
            a = a.left
        return a.data

    def RBdeletefixup(self, x):
        while x != self.__r and x.color == 1:
            if x == x.parent.left:
                w = x.parent.right
                if w.color == 0:
                    w.color = 1
                    x.parent.color = 0
                    self.rotateLeft(x.parent)
                    w = x.parent.right

                if w.left.color == 1 and w.right.color == 1:
                    w.color = 0
                    x = x.parent
                else:
                    if w.right.color == 1:
                        w.left.color = 1
                        w.color = 0
                        self.rotateRight(w)
                        w = x.parent.right

                    w.color = x.parent.color
                    x.parent.color = 1
                    w.right.color = 1
                    self.rotateLeft(x.parent)
                    x = self.__r

            else:
                w = x.parent.left
                if w.color == 0:
                    w.color = 1
                    x.parent.color = 0
                    self.rotateRight(x.parent)
                    w = x.parent.left

                if w.right.color == 1 and w.left.color == 1:
                    w.color = 0
                    x = x.parent
                else:
                    if w.left.color == 1:
                        w.right.color = 1
                        w.color = 0
                        self.rotateLeft(w)
                        w = x.parent.left

                    w.color = x.parent.color
                    x.parent.color = 1
                    w.left.color = 1
                    self.rotateRight(x.parent)
                    x = self.__r

        x.color = 1

    # delete function taken from the pseudocode given in class
    def deleteNode(self, z):
        y = z
        y_original_color = y.color
        if(z.left == self.sentinel):
            RBtransplant(self,z,z.right)
        elif(z.right == self.sentinel):
            x=z.left
            RBtransplant(self, z, z.left)
        else:
            y = TreeMinimum(z.right)
            y_original_color = y.color
            x = y.right
            if(y.parent == z):
                x.parent = y
            else:
                RBtransplant(self, y, y.right)
                y.right = z.right
                y.right.parent = y
            RBtransplant(self,z,y)
            y.left = z.left
            y.left.parent = y
            y.color = z.color
        if(y_original_color == 1):
            RBdeletefixup(self,x)


    #helper function for deleteNode function
    def RBtransplant(self, u, v):
        if (u.parent == self.sentinel):
            self.__r = v
        elif (u == u.parent.left):
            u.parent.left = v
        else:
            u.parent.right = v
        v.parent = u.parent

    def getMinimum(self):
        a = self.__r
        while (a.left.data is not None):
            a = a.left
        return a.data

    def getMaximum(self):
        a = self.__r
        while (a.right.data is not None):
            a = a.right
        return a.data

    def successor(self, x):
        if x.right:
            return self.getMinimum()
        y = x.parent
        while y and x == y.right:
            x = y
            y = y.parent
        return y

    def predecessor(self, x):
        if x.left:
            return self.getMaximum()
        y = x.parent
        while y and x == y.left:
            x = y
            y = y.parent
        return y


    def inorder(self, x=None):
        if (x is None):
            x = self.__r
        x = self.getMinimum
        while x:
            yield x.data
            x = self.successor(x)


q = RedBlackTree()
q.insert(1)
q.insert(2)
q.insert(3)
q.insert(4)
q.insert(5)

