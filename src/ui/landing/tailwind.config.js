module.exports = {
  content: [
    "./index.html",
    "./src/**/*.{vue,js,ts,jsx,tsx}",
  ],
  theme: {
    extend: {
      colors: {
        'dark-blue': '#0F165A',
        'purple': '#BE1EE5',
        'none': 'rgba(219,219, 219, 0.52)',
        'rect': 'rgba(55, 90, 177, 0.51)',
      },
      animation: {
        'slide-1': 'slide-1 8s ease-in-out 1s infinite',
        'slide-2': 'slide-2 6s ease-in-out 1.5s infinite ',
        'choose-1': 'choose 9s ease-in-out 0s infinite',
        'choose-2': 'choose 9s ease-in-out 3s infinite',
        'choose-3': 'choose 9s ease-in-out 6s infinite',
        'vertical-choose-1': 'choose 6s ease-in-out 0s infinite',
        'vertical-choose-2': 'choose 6s ease-in-out 2s infinite',
        'vertical-choose-3': 'choose 6s ease-in-out 4s infinite',
        1: 'fade-in 0.5s ease-in 0s 1 forwards',
        2: 'fade-in 0.5s ease-in 0.5s 1 forwards',
        3: 'fade-in 0.5s ease-in 1s 1 forwards',
        4: 'fade-in 0.5s ease-in 1.5s 1 forwards',
        5: 'fade-in 0.5s ease-in 2s 1 forwards',
      },
    },
  },
  plugins: [],
}
