#include "chess_pieces.h"

Chess_Piece::Chess_Piece(const Piece_Color color, const Piece_Pos& piece_pos, const Chess_Piece_Identifier piece_name)
	:m_color(color), m_piece_pos(piece_pos), m_piece_identifier(piece_name)
{
	m_if_piece_exist = true;
}


int Chess_Piece::ReturnTrackList(const Piece_Pos& destination_pos, vector<Piece_Pos>& move_track_list) const
{
	if(m_if_piece_exist == false)
		return -1;

	if(destination_pos == m_piece_pos)
		return -1;
	

	//y = ax + b
	// a counld be 0, 1 , -1	
	int a;
	if(destination_pos.x != m_piece_pos.x) // because divide by zero is not allowed
		a = (destination_pos.y - m_piece_pos.y) / (destination_pos.x - m_piece_pos.x);
	else
		a = 0;

	int b = 0;
	
	move_track_list.clear();

	// exception of x = a function 
	if(a == 0 | destination_pos.x == m_piece_pos.x)
	{
		if(destination_pos.y > m_piece_pos.y)
		{
			for(int y = m_piece_pos.y; y <= destination_pos.y; y++)
				move_track_list.push_back(Piece_Pos((m_piece_pos.x), y));
		}
		else
		{
			for(int y = m_piece_pos.y; destination_pos.y <= y; y--)
				move_track_list.push_back(Piece_Pos((m_piece_pos.x), y));
		}

		return 0;
	}
	
	b = m_piece_pos.y - ( a * m_piece_pos.x);
	
	if(destination_pos.x > m_piece_pos.x)
	{
		for(int x = m_piece_pos.x; x <= destination_pos.x; x++)
			move_track_list.push_back(Piece_Pos(x, ( a * x + b)));
	}

	else
	{
		for(int x = m_piece_pos.x; destination_pos.x <= x; x++)
			move_track_list.push_back(Piece_Pos(x, ( a * x + b)));
	}
		
	return 0;
}

bool Chess_Piece::CheckPosRange(const Piece_Pos& input_pos) const
{
	if(input_pos.x < 0 | 7 < input_pos.x) 
		return false;
	 if(input_pos.y < 0 | 7 < input_pos.y)
		return false;

	 return true;
}

bool Chess_Piece::ReturnIfPieceExist(void) const
{
	return m_if_piece_exist;
}

bool Chess_Piece::ReturnIfPieceExist(void)
{
	return m_if_piece_exist;
}

Chess_Piece_Identifier Chess_Piece::ReturnPieceIdentifier(void) const
{
	return m_piece_identifier;
}


Piece_Color Chess_Piece::ReturnPieceColor(void) const
{
	return m_color;
}

Piece_Color Chess_Piece::ReturnPieceColor(void)
{
	return m_color;
}

King::King(const Piece_Color color, const Piece_Pos& piece_pos)
	:Chess_Piece(color, piece_pos, Chess_Piece_Identifier::KING)
{
}

Queen::Queen(const Piece_Color color, const Piece_Pos& piece_pos)
	:Chess_Piece(color, piece_pos, Chess_Piece_Identifier::QUEEN)
{	
}

Pone::Pone(const Piece_Color color, const Piece_Pos& piece_pos)
	:Chess_Piece(color, piece_pos, Chess_Piece_Identifier::PONE)
{
}

Night::Night(const Piece_Color color, const Piece_Pos& piece_pos)
	:Chess_Piece(color, piece_pos, Chess_Piece_Identifier::NIGHT)
{
}

Bishop::Bishop(const Piece_Color color, const Piece_Pos& piece_pos)
	:Chess_Piece(color, piece_pos, Chess_Piece_Identifier::BISHOP)
{
}

Rook::Rook(const Piece_Color color, const Piece_Pos& piece_pos)
	:Chess_Piece(color, piece_pos, Chess_Piece_Identifier::ROOK)
{
}

int King::ReturnTrackList(const Piece_Pos& destination_pos, vector<Piece_Pos>& move_track_list) const
{
	if(ReturnIfPieceExist() == false)
		return -1;
	
	if(CheckPosRange(destination_pos) == false)
		return -1;

	if(abs(destination_pos.x - m_piece_pos.x) > 1 | abs(destination_pos.y - m_piece_pos.y) > 1)
		return -1;
	
	Chess_Piece::ReturnTrackList(destination_pos, move_track_list); 
	
	return 0;
}

int Queen::ReturnTrackList(const Piece_Pos& destination_pos, vector<Piece_Pos>& move_track_list) const
{
	if(ReturnIfPieceExist() == false)
		return -1;
	
	if(CheckPosRange(destination_pos) == false)
		return -1;
	
	
	double slop;
	if(destination_pos.x != m_piece_pos.x)
		slop = (destination_pos.y - m_piece_pos.y) / (destination_pos.x - m_piece_pos.x);	
	else
		slop == 0;

	if(!(slop == 1 | slop == -1 | slop == 0))
		return -1;

	Chess_Piece::ReturnTrackList(destination_pos, move_track_list); 
	
	return 0;
}
int Pone::ReturnTrackList(const Piece_Pos& destination_pos, vector<Piece_Pos>& move_track_list) const
{
	if(ReturnIfPieceExist() == false)
		return -1;
	
	if(CheckPosRange(destination_pos) == false)
		return -1;
	
	
	double slop;
	if(destination_pos.x != m_piece_pos.x)
		slop = (destination_pos.y - m_piece_pos.y) / (destination_pos.x - m_piece_pos.x);	
	else
		slop == 0;

	if(!(slop == 1 | slop == -1 | slop == 0))
		return -1;

	if(destination_pos.y - m_piece_pos.y != 1 | abs(destination_pos.x - m_piece_pos.x) > 1)
		return -1;
		

	Chess_Piece::ReturnTrackList(destination_pos, move_track_list); 
	
	return 0;
}

int Night::ReturnTrackList(const Piece_Pos& destination_pos, vector<Piece_Pos>& move_track_list) const
{
	//because night's track can't be expressed by y = ax + b so this function can't use ReturnTrackList func
	move_track_list.clear();

	if(ReturnIfPieceExist() == false)
		return -1;
	
	if(CheckPosRange(destination_pos) == false)
		return -1;
	
	if(abs(destination_pos.x - m_piece_pos.x) == 1 | abs(destination_pos.y - m_piece_pos.y) == 2)	
	{
		move_track_list.push_back(Piece_Pos(m_piece_pos.x, (destination_pos.y + m_piece_pos.y) / 2));
		move_track_list.push_back(destination_pos);
	}

	if(abs(destination_pos.x - m_piece_pos.x) == 2 | abs(destination_pos.y - m_piece_pos.y) == 1)	
	{	
		move_track_list.push_back(Piece_Pos((destination_pos.x + m_piece_pos.x) / 2, m_piece_pos.y));
		move_track_list.push_back(destination_pos);
	}
	
	return 0;

}

int Bishop::ReturnTrackList(const Piece_Pos& destination_pos, vector<Piece_Pos>& move_track_list) const
{
	if(ReturnIfPieceExist() == false)
		return -1;
	
	if(CheckPosRange(destination_pos) == false)
		return -1;
	
	
	double slop;
	if(destination_pos.x != m_piece_pos.x)
		slop = (destination_pos.y - m_piece_pos.y) / (destination_pos.x - m_piece_pos.x);	
	else
		slop == 0;

	if(!(slop == 1 | slop == -1))
		return -1;	

	Chess_Piece::ReturnTrackList(destination_pos, move_track_list); 

}

int Rook::ReturnTrackList(const Piece_Pos& destination_pos, vector<Piece_Pos>& move_track_list) const
{
	if(ReturnIfPieceExist() == false)
		return -1;
	
	if(CheckPosRange(destination_pos) == false)
		return -1;
	
	
	double slop;
	if(destination_pos.x != m_piece_pos.x)
		slop = (destination_pos.y - m_piece_pos.y) / (destination_pos.x - m_piece_pos.x);	
	else
		slop == 0;

	if(!(slop != 0))
		return -1;	

	Chess_Piece::ReturnTrackList(destination_pos, move_track_list); 

}















