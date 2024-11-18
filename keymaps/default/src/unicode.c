#include QMK_KEYBOARD_H

enum unicode_names
{
	// GREEK
	ALPHA_U,
	BETA_U,
	GAMMA_U,
	DELTA_U,
	EPSILON_U,
	ZETA_U,
	ETA_U,
	THETA_U,
	IOTA_U,
	KAPPA_U,
	LAMBDA_U,
	MU_U,
	NU_U,
	XI_U,
	OMICRON_U,
	PI_U,
	RHO_U,
	SIGMA_U,
	TAU_U,
	UPSILON_U,
	PHI_U,
	CHI_U,
	PSI_U,
	OMEGA_U,
	ALPHA,
	BETA,
	GAMMA,
	DELTA,
	EPSILON,
	ZETA,
	ETA,
	THETA,
	IOTA,
	KAPPA,
	LAMBDA,
	MU,
	NU,
	XI,
	OMICRON,
	PI,
	RHO,
	STIGMA,
	SIGMA,
	TAU,
	UPSILON,
	PHI,
	CHI,
	PSI,
	OMEGA,

	// Shifted math
	THERE_EXISTS,
	THERE_NOT_EXISTS,

	// Set membership (shifted)
	ELEMENT_OF,
	NOT_ELEMENT_OF,
	CONTAINS_MEMBER,
	NOT_CONTAINS_MEMBER,
	NULL_SYMBOL,
	NOT_SIGN,
	SQUARE_ROOT,
	CUBE_ROOT,
	TIMES,
	DOT,
	// Logical and set operators
	LOGICAL_AND,
	LOGICAL_OR,
	INTERSECTION,
	UNION,

	PROPORTIONAL_TO,

	// Miscellaneous math symbols
	INFINITY,

	// LETTERS
	ASH,
	ASH_U,

	// Superscript
	SUPER_0,
	SUPER_1,
	SQUARED,
	CUBED,
	SUPER_4,
	SUPER_5,
	SUPER_6,
	SUPER_7,
	SUPER_8,
	SUPER_9,
	SUPER_PLUS,
	SUPER_MINUS,
	SUPER_EQUALS,
	SUPER_LPARENTH,
	SUPER_RPARENTH,

	// Subscript
	SUB_0,
	SUB_1,
	SUB_2,
	SUB_3,
	SUB_4,
	SUB_5,
	SUB_6,
	SUB_7,
	SUB_8,
	SUB_9,
	SUB_PLUS,
	SUB_MINUS,
	SUB_EQUALS,
	SUB_LPARENTH,
	SUB_RPARENTH,

	// Fractions
	SEVENTH,
	NINTH,
	THIRD,
	TWO_THIRDS,
	FIFTH,
	TWO_FIFTHS,
	THREE_FIFTHS,
	FOUR_FIFTHS,
	SIXTH,
	FIVE_SIXTHS,
	EIGHTH,
	THREE_EIGHTHS,
	FIVE_EIGHTHS,
	SEVEN_EIGHTHS,
	ONE_OVER,
	QUARTER,
	HALF,
	THREE_QUARTERS,

	// Symbols
	INVERTED_EXCLAMATION,
	INVERTED_QUESTION,

	/* NON-SHIFTED SYMBOLS */

	// Latin-1 punctuation and symbols
	DEGREE_SIGN,

	// Mathematical Operators
	DIVIDE,

	// Superscript (non-shift)
	SUPER_N,
	SUPER_I,

	// Fractions
	TENTH,

	// Roman Numerals
	// TODO

	// Math symbols
	FOR_ALL,

	// Operators
	FOURTH_ROOT,

	// Miscellaneous
	CHECK,
	BALLOT_X,

	// Emojis
	ROFL,
	LAUGHING_TEARS,
	SMILEY_FACE,
	UPSIDE_DOWN_FACE,
	EYE_ROLL,
	GRIMACE_FACE,
	FROWNING_FACE,
	CRYING_FACE,
	DISAPPOINTED_FACE,
	THUMBS_UP,
	HEART,
};

// source:
// https://gist.github.com/ivandrofly/0fe20773bd712b303f78
const uint32_t unicode_map[] PROGMEM = {
		// Greek
		[ALPHA_U] = 0x0391,		// Α
		[BETA_U] = 0x0392,		// Β
		[GAMMA_U] = 0x0393,		// Γ
		[DELTA_U] = 0x0394,		// Δ
		[EPSILON_U] = 0x0395, // Ε
		[ZETA_U] = 0x0396,		// Ζ
		[ETA_U] = 0x0397,			// Η
		[THETA_U] = 0x0398,		// Θ
		[IOTA_U] = 0x0399,		// Ι
		[KAPPA_U] = 0x039A,		// Κ
		[LAMBDA_U] = 0x039B,	// Λ
		[MU_U] = 0x039C,			// Μ
		[NU_U] = 0x039D,			// Ν
		[XI_U] = 0x039E,			// Ξ
		[OMICRON_U] = 0x039F, // Ο
		[PI_U] = 0x03A0,			// Π
		[RHO_U] = 0x03A1,			// Ρ
		[SIGMA_U] = 0x03A3,		// Σ
		[TAU_U] = 0x03A4,			// Τ
		[UPSILON_U] = 0x03A5, // Υ
		[PHI_U] = 0x03A6,			// Φ
		[CHI_U] = 0x03A7,			// Χ
		[PSI_U] = 0x03A8,			// Ψ
		[OMEGA_U] = 0x03A9,		// Ω
		[ALPHA] = 0x03B1,			// α
		[BETA] = 0x03B2,			// β
		[GAMMA] = 0x03B3,			// γ
		[DELTA] = 0x03B4,			// δ
		[EPSILON] = 0x03B5,		// ε
		[ZETA] = 0x03B6,			// ζ
		[ETA] = 0x03B7,				// η
		[THETA] = 0x03B8,			// θ
		[IOTA] = 0x03B9,			// ι
		[KAPPA] = 0x03BA,			// κ
		[LAMBDA] = 0x03BB,		// λ
		[MU] = 0x03BC,				// μ
		[NU] = 0x03BD,				// ν
		[XI] = 0x03BE,				// ξ
		[OMICRON] = 0x03BF,		// ο
		[PI] = 0x03C0,				// π
		[RHO] = 0x03C1,				// ρ
		[SIGMA] = 0x03C3,			// σ
		[TAU] = 0x03C4,				// τ
		[UPSILON] = 0x03C5,		// υ
		[PHI] = 0x03C6,				// φ
		[CHI] = 0x03C7,				// χ
		[PSI] = 0x03C8,				// ψ
		[OMEGA] = 0x03C9,			// ω

		// Math (shifted)
		[THERE_EXISTS] = 0x2203,				// ∃
		[THERE_NOT_EXISTS] = 0x2204,		// ∄
		[ELEMENT_OF] = 0x2208,					// ∈
		[NOT_ELEMENT_OF] = 0x2209,			// ∉
		[CONTAINS_MEMBER] = 0x220B,			// ∋
		[NOT_CONTAINS_MEMBER] = 0x220C, // ∌
		[LOGICAL_AND] = 0x2227,					// ∧
		[LOGICAL_OR] = 0x2228,					// ∨
		[INTERSECTION] = 0x2229,				// ∩
		[UNION] = 0x222A,								// ∪
		[PROPORTIONAL_TO] = 0x221D,			// ∝
		[INFINITY] = 0x221E,						// ∞
		[NULL_SYMBOL] = 0x2205,					// ∅
		[NOT_SIGN] = 0x00AC,						// ¬
		[SQUARE_ROOT] = 0x221A,					// √
		[CUBE_ROOT] = 0x221B,						// ∛
		[DOT] = 0x00B7,									// ·
		[TIMES] = 0x00D7,								// ×

		// Letters
		[ASH] = 0x00E6,		// æ
		[ASH_U] = 0x00C6, // Æ

		// Superscript
		[SUPER_0] = 0x2070,				 // ⁰
		[SUPER_1] = 0x00B9,				 // ¹
		[SQUARED] = 0x00B2,				 // ²
		[CUBED] = 0x00B3,					 // ³
		[SUPER_4] = 0x2074,				 // ⁴
		[SUPER_5] = 0x2075,				 // ⁵
		[SUPER_6] = 0x2076,				 // ⁶
		[SUPER_7] = 0x2077,				 // ⁷
		[SUPER_8] = 0x2078,				 // ⁸
		[SUPER_9] = 0x2079,				 // ⁹
		[SUPER_PLUS] = 0x207A,		 // ⁺
		[SUPER_MINUS] = 0x207B,		 // ⁻
		[SUPER_EQUALS] = 0x207C,	 // ⁼
		[SUPER_LPARENTH] = 0x207D, // ⁽
		[SUPER_RPARENTH] = 0x207E, // ⁾

		// Subscript
		[SUB_0] = 0x2080,				 // ₀
		[SUB_1] = 0x2081,				 // ₁
		[SUB_2] = 0x2082,				 // ₂
		[SUB_3] = 0x2083,				 // ₃
		[SUB_4] = 0x2084,				 // ₄
		[SUB_5] = 0x2085,				 // ₅
		[SUB_6] = 0x2086,				 // ₆
		[SUB_7] = 0x2087,				 // ₇
		[SUB_8] = 0x2088,				 // ₈
		[SUB_9] = 0x2089,				 // ₉
		[SUB_PLUS] = 0x208A,		 // ₊
		[SUB_MINUS] = 0x208B,		 // ₋
		[SUB_EQUALS] = 0x208C,	 // ₌
		[SUB_LPARENTH] = 0x208D, // ₍
		[SUB_RPARENTH] = 0x208E, // ₎

		// Fractions
		[HALF] = 0x00BD,					 // ½
		[THIRD] = 0x2153,					 // ⅓
		[QUARTER] = 0x00BC,				 // ¼
		[FIFTH] = 0x2155,					 // ⅕
		[SIXTH] = 0x2159,					 // ⅙
		[SEVENTH] = 0x2150,				 // ⅐
		[EIGHTH] = 0x215B,				 // ⅛
		[NINTH] = 0x2151,					 // ⅑
		[ONE_OVER] = 0x215F,			 // ⅟
		[TWO_THIRDS] = 0x2154,		 // ⅔
		[TWO_FIFTHS] = 0x2156,		 // ⅖
		[THREE_QUARTERS] = 0x00BE, // ¾
		[THREE_FIFTHS] = 0x2157,	 // ⅗
		[THREE_EIGHTHS] = 0x215C,	 // ⅜
		[FOUR_FIFTHS] = 0x2158,		 // ⅘
		[FIVE_SIXTHS] = 0x215A,		 // ⅚
		[FIVE_EIGHTHS] = 0x215D,	 // ⅝
		[SEVEN_EIGHTHS] = 0x215E,	 // ⅞

		// Symbols
		[INVERTED_QUESTION] = 0x00BF,		 // ¿
		[INVERTED_EXCLAMATION] = 0x00A1, // ¡

		/* NON-SHIFTED LETTERS */

		// non-shifted Greek
		[STIGMA] = 0x03C2, // ς

		// Symbols
		[DEGREE_SIGN] = 0x00B0, // °

		// Math
		[FOR_ALL] = 0x2200,			// ∀
		[DIVIDE] = 0x00F7,			// ÷
		[FOURTH_ROOT] = 0x221C, // ∜

		// Fractions non-shift
		[TENTH] = 0x2152, // ⅒

		// Superscript non-shift
		[SUPER_N] = 0x207F, // ⁿ
		[SUPER_I] = 0x2071, // ⁱ

		// Emojis
		[CHECK] = 0x2713,							 // ✓
		[BALLOT_X] = 0x2717,					 // ✗
		[ROFL] = 0x1F923,							 // 🤣
		[LAUGHING_TEARS] = 0x1F602,		 // 😂
		[SMILEY_FACE] = 0x1F642,			 // 🙂
		[UPSIDE_DOWN_FACE] = 0x1F643,	 // 🙃
		[EYE_ROLL] = 0x1F644,					 // 🙄
		[GRIMACE_FACE] = 0x1F62C,			 // 😬
		[FROWNING_FACE] = 0x1F641,		 // 🙁
		[CRYING_FACE] = 0x1F62D,			 // 😭
		[DISAPPOINTED_FACE] = 0x1F61E, // 😞
		[THUMBS_UP] = 0x1F44D,				 // 👍
		[HEART] = 0x2665,							 // ♥️
};

