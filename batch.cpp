#include <bits/stdc++.h>
using namespace std;
#define alpha .00000001
#define desired_error 0.10
#define no_of_sample 10

void testing();
float h[no_of_sample];
float cal_h(int);
void w_initialisation();

// Initialise the training set
int x[no_of_sample][2] = {{500, 1}, {3000, 6}, {2000, 4}, {1500, 3}, {3500, 7}, {5000, 10}, {6000, 12},{4500, 9},{5500,11}};


// Give the testing data
int test[no_of_sample][2] = { {1000, 2},{4000, 8}};


float y[no_of_sample] = {12, 72, 48, 36, 84, 120, 144,108,132};

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
            printf("\n For Each %d", ++e);
            error=0;

            float gradient[]={0,0,0};

            for (int i = 0; i < no_of_sample; i++)
            {
                printf("\n\nHypothesis for Training sample %d= %f", i + 1, cal_h(i));
                error += 0.5 * pow((h[i] - y[i]), 2);
            }
            for(int i=0;i<no_of_sample;i++){

                gradient[0]+=alpha*(y[i]-h[i])*1;
                gradient[1]+=alpha*(y[i]-h[i])*x[i][0];
                gradient[2]+=alpha*(y[i]-h[i])*x[i][1];

            }

            for(int i=0;i<3;i++)
            {
                w[i]+=gradient[i];
            }

            error=error/10;
            cout<<"\nCost= "<<error;
            for(int i=0;i<3;i++)
            {
                cout<<"\nw"<<i<<"= "<<w[i];
            }


        }
         testing();

    return 0;
}

void testing()
{
    int i, j;
    float test_y = 0.0;

   for(int i=0;i<2;i++){
    float test_x1=test[i][0];
    float test_x2=test[i][1];
    test_y=w[0]+w[1]*test_x1+w[2]*test_x2;
    cout<<"\n";
    cout<<"predicted y for "<<test_x1<<" "<<test_x2<<" "<<test_y<<"\n";

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
    printf("\n\n cal_h= %f  %f.........", temp, h[i]);
    return h[i];
}
void w_initialisation()
{
    w[0] = 0.002010;
    w[1] = 0.023;
    w[2] = 0.004045;

}
