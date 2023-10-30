#include<bits/stdc++.h>
using namespace std;
double find_mean(double a[5]){
    double sum=0;
    for(int i=0;i<5;++i){
        sum+=a[i];
    }
    return sum/5;
}
double find_variance(double b[5],double &m){
    double sum1=0;
    for (int i = 0; i <5; i++)
    {
        sum1 = sum1 + pow((b[i] - m), 2);
    }
     return sum1 / 4;
}
int main(){
   double male_h[5]={6.1,5.94,5.65,5.58,5.92};
   double female_h[5]={5.1,5,5.5,5.46,5.73};
   double male_w[5]={180,192,180,170,165};
   double female_w[5]={105,100,150,130,148};
   double male_fsize[5]={12.1,11.8,11,10.7,10};
   double female_fsize[5]={6.2,6,8,7,9};
   double test_h[]={6};
   double test_w[]={170};
   double test_fs[]={11};
   // finding mean
   double mean_male_height=find_mean(male_h);
   double mean_female_height=find_mean(female_h);
   double mean_male_weight=find_mean(male_w);
   double mean_female_weight=find_mean(female_w);
   double mean_male_fsize=find_mean(male_fsize);
   double mean_female_fsize=find_mean(female_fsize);
   // finding variance
   double variance_male_height=find_variance(male_h,mean_male_height);
   double variance_female_height=find_variance(female_h,mean_female_height);
   double variance_male_weight=find_variance(male_w,mean_male_weight);
   double variance_female_weight=find_variance(female_w,mean_female_weight);
   double variance_male_fsize=find_variance(male_fsize,mean_male_fsize);
   double variance_female_fsize=find_variance(female_fsize,mean_female_fsize);

   // printing means and variances of male and female;
   cout<<"printing male and female mean and variances"<<endl;
   cout<<"mean height of male data is : "<<mean_male_height<<endl;
   cout<<"variance height of male data is : "<<variance_male_height<<endl;
   cout<<"mean weight of male data is : "<<mean_male_weight<<endl;
   cout<<"variance weight of male data is : "<<variance_male_weight<<endl;
    cout<<"mean fsize of male data is : "<<mean_male_fsize<<endl;
   cout<<"variance fsize of male data is : "<<variance_male_fsize<<endl;
   // for female
   cout<<"----------------------"<<endl;
   cout<<"mean height of female data is : "<<mean_female_height<<endl;
   cout<<"variance height of female data is : "<<variance_female_height<<endl;
   cout<<"mean weight of female data is : "<<mean_female_weight<<endl;
   cout<<"variance weight of female data is : "<<variance_female_height<<endl;
   cout<<"mean fsize of female data is : "<<mean_female_fsize<<endl;
   cout<<"variance fsize of female data is : "<<variance_female_fsize<<endl;

   cout<<"-----------------------------"<<endl;
   cout<<"finding probabilities and predicting"<<endl;



   int testsize = sizeof(test_h) / sizeof(double);
    for(int i = 0 ; i < 1 ; i++)
    {
        double probHeightM =( 1 / (sqrt(2 * 3.14 * variance_male_height)) * exp(-pow((test_h[i] - mean_male_height), 2) / (2 * variance_male_height)));
        printf("Prob of height of male: %e",probHeightM);
        printf(" \n");

        double probWeightM = (1 / (sqrt(2 * 3.14 * variance_male_weight)) * exp(-pow((test_w[i] - mean_male_weight), 2) / (2 * variance_male_weight)));
        printf("Prob of weight of male: %e",probWeightM);
        printf("\n ");

        double probFootsizeM =( 1 / (sqrt(2 * 3.14 *  variance_male_fsize)) * exp(-pow((test_fs[i] - mean_male_fsize), 2) / (2 * variance_male_fsize)));
        printf("Prob of footsize of male: %e",probFootsizeM);
        printf(" \n");

        double probHeightF = (1 / (sqrt(2 * 3.14 * variance_female_height)) * exp(-pow((test_h[i] - mean_female_height), 2) / (2 * variance_female_height)));
        printf("Prob of height of female: %e",probHeightF);
        printf("\n ");


        double probWeightF = (1 / (sqrt(2 * 3.14 * variance_female_weight)) * exp(-pow((test_w[i] - mean_female_weight), 2) / (2 * variance_female_weight)));
        printf("Prob of weight of female: %e",probWeightF);
        printf("\n ");

        double probFootsizeF = (1 / (sqrt(2 * 3.14 * variance_female_fsize)) * exp(-pow((test_fs[i] - mean_female_fsize), 2) / (2 * variance_female_fsize)));
        printf("Prob of footsize of female: %e",probFootsizeF);
        printf("\n");

        double Male = 0.5;
        double Female = 0.5;
        double posteriorMale = 0.5 * probHeightM * probWeightM * probFootsizeM;
        double posteriorFemale = 0.5 * probHeightF * probWeightF * probFootsizeF;
        cout<<"-------------------------"<<endl;

        printf("Posterior of male is: %e\n",posteriorMale);
        printf("Posterior of female is : %e\n", posteriorFemale);
        if (posteriorMale > posteriorFemale)
        {
            printf("The sample is male\n");
        }
        else
        {
            printf("The sample is female\n");
        }

        return 0;
    }





}
