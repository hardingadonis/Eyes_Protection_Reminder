import { useEffect, useState } from "react";
import { Transition } from "@headlessui/react";

import Home from "./pages/Home";

import arrow from "./assets/arrow.svg";
import FirstPage from "./pages/FirstPage";
import SecondPage from "./pages/SecondPage";
import ThirdPage from "./pages/ThirdPage";

const pageMessages = [
	"",
	"Easy to use",
	"Ultimately focus on your work",
	"Easily customize in your own way",
];

function App() {
	const [page, setPage] = useState(0);

	const eel = window["eel"];

	function handleNavigate(pageIndex) {
		return () => {
      if (pageIndex == 4) window.close()
			setPage(pageIndex);
		};
	}

	return (
		<div
			className="w-full h-screen relative bg-dark-blue text-white
                    before:z-0 before:block before:absolute before:blur-xl before:rotate-45 before:-top-[130px] before:left-[140px]
                    before:w-16 before:h-[600px] before:bg-purple"
		>
			{[...Array(4)].map((_, index) => (
				<Transition
					show={page == index}
					enter="transition-all duration-[1s]"
					enterFrom="opacity-0"
					enterTo="opacity-100"
					leave="transition-all duration-[1s]"
					leaveFrom="opacity-100"
					leaveTo="opacity-0"
				>
					<div className="absolute z-20 top-0 left-0 w-full h-5/6 grid place-items-center">
						{(function () {
							switch (index) {
								case 0:
									return <Home />;
								case 1:
									return <FirstPage />;
								case 2:
									return <SecondPage />;
								case 3:
									return <ThirdPage />;
							}
						})()}
					</div>
				</Transition>
			))}
			<div className="absolute left-1/2 bottom-10 -translate-x-1/2 flex gap-3">
				{[...Array(4)].map((_, index) => (
					<div
						key={index}
						onClick={handleNavigate(index)}
						className={`w-3 h-3 rounded-full ${
							page === index ? "bg-white" : "bg-none"
						} cursor-pointer`}
					></div>
				))}
			</div>
			<div
				onClick={handleNavigate(page + 1)}
				className="absolute right-12 bottom-10 flex gap-3 text-white items-center
                                                          cursor-pointer font-bold transition-all
                                                          hover:text-purple "
			>
				{page == 0 ? (
					<p>Get started</p>
				) : page == 3 ? (
					<p>Finish</p>
				) : (
					<p>Next</p>
				)}
				<img className="" src={arrow} alt="" />
			</div>
		</div>
	);
}

export default App;
