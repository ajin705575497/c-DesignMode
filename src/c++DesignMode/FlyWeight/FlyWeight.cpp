///*���������̳���*/
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
////���ӵ���ɫ
//enum PieceColor{BLACK,WHTIE};
//
////���ӵ�λ��
//struct PiecePos {
//	int m_x;
//	int m_y;
//	PiecePos(int a, int b):m_x(a),m_y(b){}
//};
//
//class Piece {
//
//public:
//	Piece(PieceColor color, PiecePos pos) :m_color(color), m_pos(pos){}
//	~Piece(){}
//	virtual void draw(){}
//
//protected:
//	PieceColor m_color;
//	PiecePos m_pos;
//};
//
//class BlackPiece :public Piece {
//public:
//	BlackPiece(PieceColor color, PiecePos pos) :Piece(color, pos) {
//
//	}
//	~BlackPiece(){}
//	void draw() {
//		cout << "����һ������" << endl;
//	}
//};
//
//class WhitePiece :public Piece {
//public:
//	WhitePiece(PieceColor color, PiecePos pos) :Piece(color, pos) {
//
//	}
//	~WhitePiece() {}
//	void draw() {
//		cout << "����һ������" << endl;
//	}
//};
//
//
//class PieceBoard {
//public:
//	PieceBoard(string blackName, string whiteName) :m_blackName(blackName), m_whiteName(whiteName) {
//
//	}
//	~PieceBoard() {
//		clear();
//	}
//
//	void setPiece(PieceColor color, PiecePos pos) {
//		Piece* pPiece = nullptr;
//		if (color == BLACK) {
//			pPiece = new BlackPiece(color, pos);
//			cout << m_blackName << "��" << pos.m_x << "," << pos.m_y << "����һ��" << endl;
//			
//		}
//		else {
//			pPiece = new WhitePiece(color, pos);
//			cout << m_whiteName << "��" << pos.m_x << "," << pos.m_y << "����һ��" << endl;
//			
//		}
//		pPiece->draw();
//		m_vecPiece.push_back(pPiece);
//	}
//	void clear() {
//		for (auto iter = m_vecPiece.begin; iter != m_vecPiece.end(); iter++)
//		{
//			delete (*iter);
//		}
//	}
//private:
//	vector<Piece*> m_vecPiece;//�����ϵ�����
//	string m_blackName;
//	string m_whiteName;
//
//};
//
//
//
//int main() {
//
//
//	system("pause");
//	return 0;
//}