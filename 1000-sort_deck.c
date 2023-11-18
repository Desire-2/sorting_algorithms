#include "deck.h"
/**
 * _str_cmp - Compares two strings.
 * @_s1: The first string to be compared.
 * @_s2: The second string to be compared.
 *
 * Return: Positive byte difference if _s1 > _s2
 *         0 if _s1 == _s2
 *         Negative byte difference if _s1 < _s2
 */
int _str_cmp(const char *_s1, const char *_s2)
{
	while (*_s1 && *_s2 && *_s1 == *_s2)
	{
		_s1++;
		_s2++;
	}

	if (*_s1 != *_s2)
		return (*_s1 - *_s2);
	return (0);
}

/**
 * getValue - Get the numerical value of a card.
 * @card: A pointer to a deck_node_t card.
 *
 * Return: The numerical value of the card.
 */
char getValue(deck_node_t *card)
{
	if (_str_cmp(card->card->value, "Ace") == 0)
		return (0);
	if (_str_cmp(card->card->value, "1") == 0)
		return (1);
	if (_str_cmp(card->card->value, "2") == 0)
		return (2);
	if (_str_cmp(card->card->value, "3") == 0)
		return (3);
	if (_str_cmp(card->card->value, "4") == 0)
		return (4);
	if (_str_cmp(card->card->value, "5") == 0)
		return (5);
	if (_str_cmp(card->card->value, "6") == 0)
		return (6);
	if (_str_cmp(card->card->value, "7") == 0)
		return (7);
	if (_str_cmp(card->card->value, "8") == 0)
		return (8);
	if (_str_cmp(card->card->value, "9") == 0)
		return (9);
	if (_str_cmp(card->card->value, "10") == 0)
		return (10);
	if (_str_cmp(card->card->value, "Jack") == 0)
		return (11);
	if (_str_cmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * _insertionSortDeckKind - Sort a deck of cards from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void _insertionSortDeckKind(deck_node_t **deck)
{
	deck_node_t *_iter, *_insert, *_tmp;

	for (_iter = (*deck)->next; _iter != NULL; _iter = _tmp)
	{
		_tmp = _iter->next;
		_insert = _iter->prev;
		while (_insert != NULL && _insert->card->kind > _iter->card->kind)
		{
			_insert->next = _iter->next;
			if (_iter->next != NULL)
				_iter->next->prev = _insert;
			_iter->prev = _insert->prev;
			_iter->next = _insert;
			if (_insert->prev != NULL)
				_insert->prev->next = _iter;
			else
				*deck = _iter;
			_insert->prev = _iter;
			_insert = _iter->prev;
		}
	}
}

/**
 * _insertionSortDeckValue - Sort a deck of cards sorted from
 *                             spades to diamonds from ace to king.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void _insertionSortDeckValue(deck_node_t **deck)
{
	deck_node_t *_iter, *_insert, *_tmp;

	for (_iter = (*deck)->next; _iter != NULL; _iter = _tmp)
	{
		_tmp = _iter->next;
		_insert = _iter->prev;
		while (_insert != NULL &&
		       _insert->card->kind == _iter->card->kind &&
		       getValue(_insert) > getValue(_iter))
		{
			_insert->next = _iter->next;
			if (_iter->next != NULL)
				_iter->next->prev = _insert;
			_iter->prev = _insert->prev;
			_iter->next = _insert;
			if (_insert->prev != NULL)
				_insert->prev->next = _iter;
			else
				*deck = _iter;
			_insert->prev = _iter;
			_insert = _iter->prev;
		}
	}
}

/**
 * _sortDeck - Sort a deck of cards from ace to king and
 *             from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void _sortDeck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	_insertionSortDeckKind(deck);
	_insertionSortDeckValue(deck);
}
