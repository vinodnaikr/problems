#include<bits/stdc++.h>
#define alpha .00000001
#define desired_error 0.10
#define no_of_sample 8

void testing();
float h[no_of_sample];
float cal_h(int);
void w_initialisation();

// Initialise the training set
int x[no_of_sample][2] = {{500, 1}, {3000, 6},{1000, 2},{2000, 4}, {1500, 3},{3500,7},{5000,10},{6000,12}};
//{1000, 2}, {2000, 4}, {1500, 3},{3500,7},{5000,10},{6000,12}

// Give the testing data
int test[no_of_sample][2] = {{3000, 9},{5500, 11}};
//, {5500, 11}

float y[no_of_sample] = {12,72,24,48,36,84,120,144};
//24, 48,,36,84,120,144
float w[3];
int e = 0;
int main()
{
    int i, j;
    float error = 1;
    w_initialisation();
    double lr = alpha;
    printf("\n For the Learning rate alpha=%e", lr);
    printf("\n Initial Weights are: w[0]=%f,w[1]=%f,w[2]=%f", w[0], w[1], w[2]);
    while (error > desired_error)
    {
        printf("\n For Epoch %d", ++e);

        for (i = 0; i < no_of_sample && error > desired_error; i++)

        {

            printf("\n\nHypothesis for Training sample %d= %f", i + 1, cal_h(i));
            error = 0.5 * pow((h[i] - y[i]), 2);
            printf("\nCost= %f", error);
            for (j = 0; j < 3; j++)
            {
                if (j == 0)
                {
                    w[0] = w[0] + alpha * (y[i] - h[i]) * 1;
                    printf("\n Weight Updated Values");
                    printf("\nw%d=%f", j, w[j]);
                }
                else
                {

                    w[j] = w[j] + alpha * (y[i] - h[i]) * x[i][j - 1];

                    printf("\nw%d=%f", j, w[j]);
                }
            }
        }
    }
    testing();
    return 0;
}

void testing()
{
    int i, j;
    float test_y = 0.0;
    for (i = 0; i < 2; i++)
    {
        test_y = 0.0;
        for (j = 0; j < 3; j++)
        {
            if (j == 0)
            {
                test_y = w[0];
            }
            else
                test_y = test_y + w[j] * test[i][j - 1];
        }

        printf("\n\n test_y for test set {%d,%d}=%f\n", test[i][0], test[i][1], test_y);
    }
}

float cal_h(int i)
{
    int j;
    float temp = 0.0;
    for (j = 0; j < 3; j++)
    {
        if (j == 0)
        {
            temp = w[0];
        }
        else
        {
            temp = temp + w[j] * x[i][j - 1];
        }
    }
    h[i] = temp;
   printf("\n\n cal_h= %f  %f.........", temp,h[i]);
    return h[i];
}
void w_initialisation()
{
    w[0] = 0.002012;
    w[1] = 0.024;
    w[2] = 0.004045;
}
