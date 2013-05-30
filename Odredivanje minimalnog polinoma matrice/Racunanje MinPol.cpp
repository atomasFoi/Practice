#include <iostream>
#include "Eigen/Eigen/Dense"
using namespace Eigen;
using namespace std;

int main()
{
	char jos = 'D';
	
	while (jos == 'D'){
		
		cout << " *************************************** " <<endl<<endl;
		cout << " RACUNANJE MINIMALNOG POLINOMA MATRICE " <<endl<<endl;
		cout << " Izradili: \n\tTomas\tTrupina\tVunak "<<endl<<endl;
		cout << " *************************************** " <<endl<<endl;
		
		int red;  //red matrice
		typedef Matrix<long double, Dynamic, Dynamic> MatrixXd; //definiranje dinamièke matrice tipa integer
		
		typedef Matrix<int, Dynamic, Dynamic> MatrixId;
		do{
			cout << "Unesite red matrice: "; cin >> red;
			if(red<2 || red > 5) cout << "Unijeli ste red manji od 2 ili veci od 5!"<<endl<<endl;
		}while(red <2 || red > 5);
		
		MatrixXd I = MatrixXd::Identity(red,red); //jedinièna matrica
		cout <<endl;
		MatrixXd A(red, red); //matrica A
		for (int i=0; i<red; i++){
			for (int j=0; j<red; j++){
				cout << "  unesite A( " <<i+1<< ", "<<j+1<<" ): "; cin >> A(i,j);
			}
		}
		//ispis matrica koje trenutno imamo na raspolaganju
		cout <<endl<<"Unijeli ste matricu A:"<<endl<< A;
		cout <<endl<<endl<<"Jedinicna matrica za ovaj zadatak:"<<endl<< I;
		
		//kreiranje prvog reda matrica, to su one A na kvadrat, na treæu, èetvrtu,...
		MatrixXd Ae2(red, red); Ae2 = A * A;
		MatrixXd Ae3(red, red); Ae3 = Ae2 * A; 
		MatrixXd Ae4(red, red); Ae4 = Ae3 * A;
		MatrixXd Ae5(red, red); Ae5 = Ae4 * A; 
		
		MatrixXd Null(red, red); Null = A-A;
		cout << endl<< "Null matrica: \n"<<Null<<endl;
		MatrixId Nullint(red, red); for(int i=0;i<red;i++)for(int j=0; j<red; j++){Nullint(i,j)=0;}
		
		//PRVI element u svakoj matrici je A(0,0)
		
		MatrixXd A11(red, red), A12(red, red), A13(red, red), A14(red, red), A15(red, red), A22(red, red), A23(red, red), A24(red, red), A25(red, red), A33(red, red), A34(red, red), A35(red, red), A44(red, red), A45(red, red), A55(red, red);
		
		long double b11, b12, b13, b14, b15, b22, b23, b24, b25, b33, b34, b35, b44, b45, b55;
		
		MatrixId A555(red, red);
		
		switch (red){
			case 2:
				
				b11 = A(0,0);
				A11 = A - b11*I;
				if (A11 == Null){
					cout <<endl<<endl<< "A11: \n"<<A11<<"\n\t\t je MINIMALNI polinom!";
					cout<<"\n\t\tA - "<<b11<<"I"<<endl;
					goto kraj_case2; 
				}
		
				b12 = Ae2(0,0);
				A12 = Ae2 - b12*I;
				if (A12 == Null){
					cout <<endl<<endl<< "A12: \n"<<A12<<"\n\t\t je MINIMALNI polinom!";
					cout<<"\n\t\tA^2 - "<<b12<<"I"<<endl;
					goto kraj_case2; 
				}
				
				b13 = Ae3(0,0);
				A13 = Ae3 - b13*I;	
				if (A13 == Null){
					cout <<endl<<endl<< "A13: \n"<<A13<<"\n\t\t je MINIMALNI polinom!";
					cout<<"\n\t\tA^3 - "<<b13<<"I"<<endl;
					goto kraj_case2; 
				}
							
				for (int i=0; i<red; i++){
					for (int j=0; j<red; j++){
						if (A12(i,j) == 0 && A11(i,j)!=0){
							A22 = A12 - 0*A11;
						}
						else if (A12(i,j) != 0){
							b22=A12(i,j)/A11(i,j); A22 = A12 - b22*A11; if(A22==Null){cout<<"\n\nA22:\n"<<A22<<"\n\t\t je MINIMALNI polinom!"; 
							cout<<"\n\n\t\t(A^2) - ("<<b22<<"A) + ("<< (b22*b11) - b12 <<"I)"<<endl;
							goto kraj_case2;}
						}
					}
				}
				
				kraj_case2:
				break;
			case 3:
				
				b11 = A(0,0);
				A11 = A - b11*I;	
				if (A11 == Null){
					cout <<endl<<endl<< "A11: \n"<<A11<<"\n\t\t je MINIMALNI polinom!";
					cout<<"\n\t\tA - "<<b11<<"I"<<endl;
					goto kraj_case3; 
				}
		
				b12 = Ae2(0,0);
				A12 = Ae2 - b12*I; 
				if (A12 == Null){
					cout <<endl<<endl<< "A12: \n"<<A12<<"\n\t\t je MINIMALNI polinom!";
					cout<<"\n\t\tA^2 - "<<b12<<"I"<<endl;
					goto kraj_case3; 
				}
				
				b13 = Ae3(0,0);
				A13 = Ae3 - b13*I;	
				if (A13 == Null){
					cout <<endl<<endl<< "A13: \n"<<A13<<"\n\t\t je MINIMALNI polinom!";
					cout<<"\n\t\tA^3 - "<<b13<<"I"<<endl;
					goto kraj_case3; 
				}
							
				for (int i=0; i<red; i++){
					for (int j=0; j<red; j++){
						if (A12(i,j) == 0 && A11(i,j)!=0){
							b22=0; A22 = A12 - 0*A11; cout <<"TU SAM BIO";
							b23=A13(i,j)/A11(i,j); A23 = A13 - b23*A11; if(A23==Null){cout<<"\n\nA23:\n"<<A23<<"\n\t\t je MINIMALNI polinom!";
							cout<<"\n\n\t\t(A^3) - ("<<b23<<"A) + ("<< (b23*b11) - b13 <<"I)"<<endl;
							goto kraj_case3;}
						}  
						else if (A12(i,j) != 0){
							b22=A12(i,j)/A11(i,j); A22 = A12 - b22*A11; if(A22==Null){cout<<"\n\nA22:\n"<<A22<<"\n\t\t je MINIMALNI polinom!";
							cout<<"\n\n\t\t(A^2) - ("<<b22<<"A) + ("<< (b22*b11) - b12 <<"I)"<<endl;
							goto kraj_case3;}
							b23=A13(i,j)/A11(i,j); A23 = A13 - b23*A11; if(A23==Null){cout<<"\n\nA23:\n"<<A23<<"\n\t\t je MINIMALNI polinom!";
							cout<<"\n\n\t\t(A^3) - ("<<b23<<"A) + ("<< (b23*b11) - b13 <<"I)"<<endl;
							goto kraj_case3;}
							goto kraj_3A2;
						}
					}
				}
				
				kraj_3A2:
				for (int i=0; i<red; i++){
					for (int j=0; j<red; j++){
						if (A23(i,j) == 0 && A22(i,j)!=0){
							b33=0; A33 = A23 - 0*A22;
						}
						else if (A23(i,j) != 0){
							b33=A23(i,j)/A22(i,j); A33 = A23 - b33*A22; if(A33==Null){cout<<"\n\nA33: \n"<<A33<<"\n\t\t je MINIMALNI polinom!";
							cout<<"\n\n\t\t(A^3) - ("<<b33<<"A^2) + ("<< b33*b22-b23 <<"A) + ("<< ((b23*b11)-b13) + (b33*b12) - (b33*b22*b11) <<"I)\n";
							goto kraj_case3;}
						}
					}
				}
				
				kraj_case3:
				break;
			case 4: 
				
				b11 = A(0,0);
				A11 = A - b11*I;
				if (A11 == Null){
					cout <<endl<<endl<< "A11: \n"<<A11<<"\n\t\t je MINIMALNI polinom!";
					cout<<"\n\t\tA - "<<b11<<"I"<<endl;
					goto kraj_case4; 
				}
		
				b12 = Ae2(0,0);
				A12 = Ae2 - b12*I;
				if (A12 == Null){
					cout <<endl<<endl<< "A12: \n"<<A12<<"\n\t\t je MINIMALNI polinom!";
					cout<<"\n\t\tA^2 - "<<b12<<"I"<<endl;
					goto kraj_case4; 
				}
				
				b13 = Ae3(0,0);
				A13 = Ae3 - b13*I;	
				if (A13 == Null){
					cout <<endl<<endl<< "A13: \n"<<A13<<"\n\t\t je MINIMALNI polinom!";
					cout<<"\n\t\tA^3 - "<<b13<<"I"<<endl;
					goto kraj_case4; 
				}
				
				b14 = Ae4(0,0);
				A14 = Ae4 - b14*I;	
				if (A14 == Null){
					cout <<endl<<endl<< "A14: \n"<<A14<<"\n\t\t je MINIMALNI polinom!";
					cout<<"\n\t\tA^4 - "<<b14<<"I"<<endl;
					goto kraj_case4; 
				}
							
				for (int i=0; i<red; i++){
					for (int j=0; j<red; j++){
						if (A12(i,j) == 0 && A11(i,j)!=0){
							A22 = A12 - 0*A11; 
							b23=A13(i,j)/A11(i,j); A23 = A13 - b23*A11; if(A23==Null){cout<<"\n\nA23:\n"<<A23<<"\n\t\t je MINIMALNI polinom!";
							cout<<"\n\n\t\t(A^3) - ("<<b23<<"A) + ("<< (b23*b11) - b13 <<"I)"<<endl;
							goto kraj_case4;}
							b24=A14(i,j)/A11(i,j); A24 = A14 - b24*A11; if(A24==Null){cout<<"\n\nA24:\n"<<A24<<"\n\t\t je MINIMALNI polinom!";
							cout<<"\n\n\t\t(A^4) - ("<<b24<<"A) + ("<< (b24*b11) - b14 <<"I)"<<endl;
							goto kraj_case4;}
							goto kraj_4A2;
						}  
						else if (A12(i,j) != 0){
							b22=A12(i,j)/A11(i,j); A22 = A12 - b22*A11; if(A22==Null){cout<<"\n\nA22:\n"<<A22<<"\n\t\t je MINIMALNI polinom!";
							cout<<"\n\n\t\t(A^2) - ("<<b22<<"A) + ("<< (b22*b11) - b12 <<"I)"<<endl;
							goto kraj_case4;}
							b23=A13(i,j)/A11(i,j); A23 = A13 - b23*A11; if(A23==Null){cout<<"\n\nA23:\n"<<A23<<"\n\t\t je MINIMALNI polinom!";
							cout<<"\n\n\t\t(A^3) - ("<<b23<<"A) + ("<< (b23*b11) - b13 <<"I)"<<endl;
							goto kraj_case4;}
							b24=A14(i,j)/A11(i,j); A24 = A14 - b24*A11; if(A24==Null){cout<<"\n\nA24:\n"<<A24<<"\n\t\t je MINIMALNI polinom!";
							cout<<"\n\n\t\t(A^4) - ("<<b24<<"A) + ("<< (b24*b11) - b14 <<"I)"<<endl;
							goto kraj_case4;}
							goto kraj_4A2;
						}
					}
				}
				
				kraj_4A2:
				for (int i=0; i<red; i++){
					for (int j=0; j<red; j++){
						if (A23(i,j) == 0 && A22(i,j)!=0){
							A33 = A23 - 0*A22;
							b34=A24(i,j)/A22(i,j); A34 = A24 - b34*A22; if(A34==Null){cout<<"\n\nA34:\n"<<A34<<"\n\t\t je MINIMALNI polinom!";
							cout<<"\n\n\t\t(A^4) - ("<<b34<<"A^2) + ("<< b34*b22-b24 <<"A) + ("<< ((b24*b11)-b14) + (b34*b12) - (b34*b22*b11) <<"I)\n";
							goto kraj_case4;} 
							goto kraj_4A3;
						}
						else if (A23(i,j) != 0){
							b33=A23(i,j)/A22(i,j); A33 = A23 - b33*A22; if(A33==Null){cout<<"\n\nA33: \n"<<A33<<"\n\t\t je MINIMALNI polinom!";
							cout<<"\n\n\t\t(A^3) - ("<<b33<<"A^2) + ("<< b33*b22-b23 <<"A) + ("<< ((b23*b11)-b13) + (b33*b12) - (b33*b22*b11) <<"I)\n";
							goto kraj_case4;} 
							b34=A24(i,j)/A22(i,j); A34 = A24 - b34*A22; if(A34==Null){cout<<"\n\nA34:\n"<<A34<<"\n\t\t je MINIMALNI polinom!";
							cout<<"\n\n\t\t(A^4) - ("<<b34<<"A^2) + ("<< b34*b22-b24 <<"A) + ("<< ((b24*b11)-b14) + (b34*b12) - (b34*b22*b11) <<"I)\n";
							goto kraj_case4;} 
							goto kraj_4A3;
						}
					}
				}
				
				kraj_4A3:
				for (int i=0; i<red; i++){
					for (int j=0; j<red; j++){
						if (A34(i,j) == 0 && A33(i,j)!=0){
							A44 = A34 - 0*A33;
						}
						else if (A34(i,j) != 0){
							b44=A34(i,j)/A33(i,j); A44 = A34 - b44*A33; if(A44==Null){cout<<"\n\nA44: \n"<<A44<<"\n\t\t je MINIMALNI polinom!";
							cout<<"\n\n\t(A^4) - ("<<b44<<"A^3) + ("<<b44*b33-b34<<"A^2) + ("<< (b34*b22-b24)-b44*(b33*b22-b23)<<"A) + ("<<(((b24*b11)-b14)+(b34*b12)-(b34*b22*b11)) - (b44*(((b23*b11)-b13)+(b33*b12)-(b33*b22*b11)))<<"I)"<<endl; 
							goto kraj_case4;}
						}
					}
				}
				
				kraj_case4:
				break;
			case 5: 
				
				b11 = A(0,0);
				A11 = A - b11*I;
				if (A11 == Null){
					cout <<endl<<endl<< "A11: \n"<<A11<<"\n\t\t je MINIMALNI polinom!";
					cout<<"\n\t\tA - "<<b11<<"I"<<endl;
					goto kraj_case5; 
				}
		
				b12 = Ae2(0,0);
				A12 = Ae2 - b12*I;
				if (A12 == Null){
					cout <<endl<<endl<< "A12: \n"<<A12<<"\n\t\t je MINIMALNI polinom!";
					cout<<"\n\t\tA^2 - "<<b12<<"I"<<endl;
					goto kraj_case5; 
				}
				
				b13 = Ae3(0,0);
				A13 = Ae3 - b13*I;	
				if (A13 == Null){
					cout <<endl<<endl<< "A13: \n"<<A13<<"\n\t\t je MINIMALNI polinom!";
					cout<<"\n\t\tA^3 - "<<b13<<"I"<<endl;
					goto kraj_case5; 
				}
				
				b14 = Ae4(0,0);
				A14 = Ae4 - b14*I;	
				if (A14 == Null){
					cout <<endl<<endl<< "A14: \n"<<A14<<"\n\t\t je MINIMALNI polinom!";
					cout<<"\n\t\tA^4 - "<<b14<<"I"<<endl;
					goto kraj_case5; 
				}
				
				b15 = Ae5(0,0);
				A15 = Ae5 - b15*I;	
				if (A15 == Null){
					cout <<endl<<endl<< "A15: \n"<<A15<<"\n\t\t je MINIMALNI polinom!";
					cout<<"\n\t\tA^5 - "<<b15<<"I"<<endl;
					goto kraj_case5; 
				}
							
				for (int i=0; i<red; i++){
					for (int j=0; j<red; j++){
						if (A12(i,j) == 0 && A11(i,j)!=0){
							b22=0; A22 = A12 - 0*A11;
							b23=A13(i,j)/A11(i,j); A23 = A13 - b23*A11; if(A23==Null){cout<<"\n\nA23:\n"<<A23<<"\n\t\t je MINIMALNI polinom!";
							cout<<"\n\n\t\t(A^3) - ("<<b23<<"A) + ("<< (b23*b11) - b13 <<"I)"<<endl;
							goto kraj_case5;}
							b24=A14(i,j)/A11(i,j); A24 = A14 - b24*A11; if(A24==Null){cout<<"\n\nA24:\n"<<A24<<"\n\t\t je MINIMALNI polinom!";
							cout<<"\n\n\t\t(A^4) - ("<<b24<<"A) + ("<< (b24*b11) - b14 <<"I)"<<endl;
							goto kraj_case5;}
							b25=A15(i,j)/A11(i,j); A25 = A15 - b25*A11; if(A25==Null){cout<<"\n\nA25:\n"<<A25<<"\n\t\t je MINIMALNI polinom!";
							cout<<"\n\n\t\t(A^5) - ("<<b25<<"A) + ("<< (b25*b11) - b15 <<"I)"<<endl;
							goto kraj_case5;}
							goto kraj_5A2;
						}  
						else if (A12(i,j) != 0){
							b22=A12(i,j)/A11(i,j); A22 = A12 - b22*A11; if(A22==Null){cout<<"\n\nA22:\n"<<A22<<"\n\t\t je MINIMALNI polinom!";
							cout<<"\n\n\t\t(A^2) - ("<<b22<<"A) + ("<< (b22*b11) - b12 <<"I)"<<endl;
							goto kraj_case5;}
							b23=A13(i,j)/A11(i,j); A23 = A13 - b23*A11; if(A23==Null){cout<<"\n\nA23:\n"<<A23<<"\n\t\t je MINIMALNI polinom!";
							cout<<"\n\n\t\t(A^3) - ("<<b23<<"A) + ("<< (b23*b11) - b13 <<"I)"<<endl;
							goto kraj_case5;}
							b24=A14(i,j)/A11(i,j); A24 = A14 - b24*A11; if(A24==Null){cout<<"\n\nA24:\n"<<A24<<"\n\t\t je MINIMALNI polinom!";
							cout<<"\n\n\t\t(A^4) - ("<<b24<<"A) + ("<< (b24*b11) - b14 <<"I)"<<endl;
							goto kraj_case5;}
							b25=A15(i,j)/A11(i,j); A25 = A15 - b25*A11; if(A25==Null){cout<<"\n\nA25:\n"<<A25<<"\n\t\t je MINIMALNI polinom!";
							cout<<"\n\n\t\t(A^5) - ("<<b25<<"A) + ("<< (b25*b11) - b15 <<"I)"<<endl;
							goto kraj_case5;}
							goto kraj_5A2;
						}
					}
				}
				
				kraj_5A2:
				for (int i=0; i<red; i++){
					for (int j=0; j<red; j++){
						if (A23(i,j) == 0 && A22(i,j)!=0){
							b33=0; A33 = A23 - 0*A22;
							b34=A24(i,j)/A22(i,j); A34 = A24 - b34*A22; if(A34==Null){cout<<"\n\nA34:\n"<<A34<<"\n\t\t je MINIMALNI polinom!";
							cout<<"\n\n\t\t(A^4) - ("<<b34<<"A^2) + ("<< b34*b22-b24 <<"A) + ("<< ((b24*b11)-b14) + (b34*b12) - (b34*b22*b11) <<"I)\n";
							goto kraj_case5;}
							b35=A25(i,j)/A22(i,j); A35 = A25 - b35*A22; if(A35==Null){cout<<"\n\nA35:\n"<<A35<<"\n\t\t je MINIMALNI polinom!";
							cout<<"\n\n\t\t(A^4) - ("<<b34<<"A^2) + ("<< b34*b22-b24 <<"A) + ("<< ((b24*b11)-b14) + (b34*b12) - (b34*b22*b11) <<"I)\n";
							goto kraj_case5;}  
							goto kraj_5A3;
						}
						else if (A23(i,j) != 0){
							b33=A23(i,j)/A22(i,j); A33 = A23 - b33*A22; if(A33==Null){cout<<"\n\nA33: \n"<<A33<<"\n\t\t je MINIMALNI polinom!";
							cout<<"\n\n\t\t(A^3) - ("<<b33<<"A^2) + ("<< b33*b22-b23 <<"A) + ("<< ((b23*b11)-b13) + (b33*b12) - (b33*b22*b11) <<"I)\n";
							goto kraj_case5;} 
							b34=A24(i,j)/A22(i,j); A34 = A24 - b34*A22; if(A34==Null){cout<<"\n\nA34:\n"<<A34<<"\n\t\t je MINIMALNI polinom!";
							cout<<"\n\n\t\t(A^4) - ("<<b34<<"A^2) + ("<< b34*b22-b24 <<"A) + ("<< ((b24*b11)-b14) + (b34*b12) - (b34*b22*b11) <<"I)\n";
							goto kraj_case5;} 
							b35=A25(i,j)/A22(i,j); A35 = A25 - b35*A22; if(A35==Null){cout<<"\n\nA35:\n"<<A35<<"\n\t\t je MINIMALNI polinom!";
							cout<<"\n\n\t\t(A^5) - ("<<b35<<"A^2) + ("<< b35*b22-b25 <<"A) + ("<< ((b25*b11)-b15) + (b35*b12) - (b35*b22*b11) <<"I)\n";
							goto kraj_case5;} 
							goto kraj_5A3;
						}
					}
				}
				
				kraj_5A3:
				for (int i=0; i<red; i++){
					for (int j=0; j<red; j++){
						if (A34(i,j) == 0 && A33(i,j)!=0){
							b44=0; A44 = A34 - 0*A33;  
							b45=A35(i,j)/A33(i,j); A45 = A35 - b45*A33; if(A45==Null){cout<<"\n\nA45:\n"<<A45<<"\n\t\t je MINIMALNI polinom!";
							cout<<"\n\n\t(A^5) - ("<<b45<<"A^3) + ("<<b45*b33-b35<<"A^2) + ("<< (b35*b22-b25)-b45*(b33*b22-b23)<<"A) + ("<<(((b25*b11)-b15)+(b35*b12)-(b35*b22*b11)) - (b45*(((b23*b11)-b13)+(b33*b12)-(b33*b22*b11)))<<"I)"<<endl; 
							
							goto kraj_case5;} 
							goto kraj_5A4;
						}
						else if (A34(i,j) != 0){
							b44=A34(i,j)/A33(i,j); A44 = A34 - b44*A33; if(A44==Null){cout<<"\n\nA44: \n"<<A44<<"\n\t\t je MINIMALNI polinom!";
							cout<<"\n\n\t(A^4) - ("<<b44<<"A^3) + ("<<b44*b33-b34<<"A^2) + ("<< (b34*b22-b24)-b44*(b33*b22-b23)<<"A) + ("<<(((b24*b11)-b14)+(b34*b12)-(b34*b22*b11)) - (b44*(((b23*b11)-b13)+(b33*b12)-(b33*b22*b11)))<<"I)"<<endl; 
							
							goto kraj_case5;}  
							b45=A35(i,j)/A33(i,j); A45 = A35 - b45*A33; if(A45==Null){cout<<"\n\nA45:\n"<<A45<<"\n\t\t je MINIMALNI polinom!";
							cout<<"\n\n\t(A^5) - ("<<b45<<"A^3) + ("<<b45*b33-b35<<"A^2) + ("<< (b35*b22-b25)-b45*(b33*b22-b23)<<"A) + ("<<(((b25*b11)-b15)+(b35*b12)-(b35*b22*b11)) - (b45*(((b23*b11)-b13)+(b33*b12)-(b33*b22*b11)))<<"I)"<<endl; 
							
							goto kraj_case5;} 
							goto kraj_5A4;
						}
					}
				}
				
				kraj_5A4:
				for (int i=0; i<red; i++){
					for (int j=0; j<red; j++){
						if (A45(i,j) == 0 && A44(i,j)!=0){
							A55 = A45 - 0*A44; 
						}
						else if  (A45(i,j) != 0){
							b55 = A45(i,j) / A44(i,j);
							A55 = A45 - b55*A44;
							for (int i=0; i<red; i++){
								for (int j=0; j<red; j++){ A555(i,j) = int(A55(i,j)); }}
							if (A555 == Nullint){cout <<endl<<endl<< "A55: \n"<<A555<<"\n\t\t je MINIMALNI polinom!";
								cout<<"\n\n\t\t(A^5) - ("<<b55<<"A^4) + ("<<b44*b55-b45<<"A^3) + ("<<(b45*b33-b35)- (b55*(b44*b33-b34))<<"A^2) + ("<< ((b35*b22-b25)-b45*(b33*b22-b23)) - (b55*( (b34*b22-b24)-b44*(b33*b22-b23)))<<"A)+ ("<<((((b25*b11)-b15)+(b35*b12)-(b35*b22*b11)) - (b45*(((b23*b11)-b13)+(b33*b12)-(b33*b22*b11))))-( b55*((((b24*b11)-b14)+(b34*b12)-(b34*b22*b11)) - (b44*(((b23*b11)-b13)+(b33*b12)-(b33*b22*b11)))))<<"I)";
								
								goto kraj_case5;
							}
							else if (A55 == Null) {
								cout <<endl<<endl<< "A55: \n"<<A55<<"\n\t\t je MINIMALNI polinom!";
								cout<<"\n\n\t\t(A^5) - ("<<b55<<"A^4) + ("<<b44*b55-b45<<"A^3) + ("<<(b45*b33-b35)- (b55*(b44*b33-b34))<<"A^2) + ("<< ((b35*b22-b25)-b45*(b33*b22-b23)) - (b55*( (b34*b22-b24)-b44*(b33*b22-b23)))<<"A)+ ("<<((((b25*b11)-b15)+(b35*b12)-(b35*b22*b11)) - (b45*(((b23*b11)-b13)+(b33*b12)-(b33*b22*b11))))-( b55*((((b24*b11)-b14)+(b34*b12)-(b34*b22*b11)) - (b44*(((b23*b11)-b13)+(b33*b12)-(b33*b22*b11)))))<<"I)";

								goto kraj_case5;
							} 
						}
					}
				}
				kraj_case5:
				break;
		}
		
		cout <<endl<<endl<<"Zelite li pokusati ponovno?  <D ili N>\n:"; cin >> jos;	
	}
		  
	return 0;
}
