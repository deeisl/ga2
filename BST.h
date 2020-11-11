#pragma once
#include <iostream>
#include <fstream>
#include "table.h"


struct node {
    node* left = NULL;
    node* right = NULL;
    int data;
};

class BST{
  private:
      node* root;

  public:

      node* getroot() {
          return root;
      }

    void add(node*& curr, int x) {
        node* temp = new node;
        temp->data = x;
        temp->left = NULL;
        temp->right = NULL;

        if (root == 0) {
            curr = temp;
        }

        else if (x > curr->data) {
            if (curr->right != NULL) {
                add(curr->left, x);
            }
            else {
                curr->right = temp;
            }
        }

        else if (x < curr->data) {
            if (curr->left != NULL) {
                add(curr->left, x);
            }
            else {
                curr->left = temp;
            }
        }

        else {
            return;
        }
    }

    bool search(node* curr, int x) {
        if (x > curr->data) {
            if (curr->right != NULL)
                return search(curr->right, x);
            else
                return false;
        }
        else if (x < curr->data) {
            if (curr->left != NULL)
                return search(curr->left, x);
            else
                return false;
        }
        else {
            return true;
        }
    }

    int value(string s)// this func converts the "aabbaa" to a sum of Ascii values
    {
        int sum_char = 0;

        // loop to sum the ascii 
        // value of chars 
        for (int i = 0; i < s.length(); i++)
        {
            sum_char += (int)s[i];
        }

        // Return the product 
        return sum_char;
    }
};