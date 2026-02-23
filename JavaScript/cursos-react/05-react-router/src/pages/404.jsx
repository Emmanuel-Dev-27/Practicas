import { Link } from "../Link";

export default function Page404() {
  return (
    <>
      <div>
        <h1>This is NOT fine</h1>
        <img src="/public/this-is-fine-404.gif" alt="This is NOT fine" />
      </div>
      <Link to='/'> Volver a la home </Link>
    </>
  )
}